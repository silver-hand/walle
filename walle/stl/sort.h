#ifndef WALLE_STL_SORT_H_
#define WALLE_STL_SORT_H_
#include <iterator>
#include <memory>
#include <functional>

namespace std {

// insertion sort

template <typename BidirectionalIterator, typename StrictWeakOrdering>
void insertion_sort(BidirectionalIterator first, BidirectionalIterator last, StrictWeakOrdering compare)
{        
	typedef typename iterator_traits<BidirectionalIterator>::value_type value_type;
	if(first != last) {
		BidirectionalIterator iCurrent, iNext, iSorted = first;

		for(++iSorted; iSorted != last; ++iSorted) {
			const value_type temp(*iSorted);
			iNext = iCurrent = iSorted;
			for(--iCurrent; (iNext != first) && compare(temp, *iCurrent); --iNext, --iCurrent) {
				*iNext = *iCurrent;
			}

			*iNext = temp;
		}
	}
} // insertion_sort


template <typename BidirectionalIterator>
void insertion_sort(BidirectionalIterator first, BidirectionalIterator last)
{
	typedef typename std::iterator_traits<BidirectionalIterator>::value_type value_type;

	if(first != last)
	{
	   BidirectionalIterator iCurrent, iNext, iSorted = first;

	   for(++iSorted; iSorted != last; ++iSorted)
	   {
		   const value_type temp(*iSorted);

		   iNext = iCurrent = iSorted;

		   for(--iCurrent; (iNext != first) && (temp < *iCurrent); --iNext, --iCurrent)
		   {
			   *iNext = *iCurrent;
		   }

		   *iNext = temp;
	   }
	}
} // insertion_sort

template <typename RandomAccessIterator, typename StrictWeakOrdering>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last, StrictWeakOrdering compare)
{
   typedef typename std::iterator_traits<RandomAccessIterator>::difference_type difference_type;

   // We use the Knuth 'h' sequence below, as it is easy to calculate at runtime. 
   // However, possibly we are better off using a different sequence based on a table.
   // One such sequence which averages slightly better than Knuth is:
   //	 1, 5, 19, 41, 109, 209, 505, 929, 2161, 3905, 8929, 16001, 36289, 
   //	 64769, 146305, 260609, 587521, 1045505, 2354689, 4188161, 9427969, 16764929

   if(first != last)
   {
	   RandomAccessIterator iCurrent, iBack, iSorted, iInsertFirst;
	   difference_type		nSize  = last - first;
	   difference_type		nSpace = 1; // nSpace is the 'h' value of the ShellSort algorithm.

	   while(nSpace < nSize)
		   nSpace = (nSpace * 3) + 1; // This is the Knuth 'h' sequence: 1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484, 7174453, 21523360, 64570081, 193710244, 

	   for(nSpace = (nSpace - 1) / 3; nSpace >= 1; nSpace = (nSpace - 1) / 3)  // Integer division is less than ideal.
	   {
		   for(difference_type i = 0; i < nSpace; i++)
		   {
			   iInsertFirst = first + i;

			   for(iSorted = iInsertFirst + nSpace; iSorted < last; iSorted += nSpace)
			   {
				   iBack = iCurrent = iSorted;
				   
				   for(iBack -= nSpace; (iCurrent != iInsertFirst) && compare(*iCurrent, *iBack); iCurrent = iBack, iBack -= nSpace)
				   {
					   std::iter_swap(iCurrent, iBack);
				   }
			   }
		   }
	   }
   }
} // shell_sort


template <typename RandomAccessIterator>
inline void shell_sort(RandomAccessIterator first, RandomAccessIterator last)
{
	typedef std::less<typename std::iterator_traits<RandomAccessIterator>::value_type> Less;

	std::shell_sort<RandomAccessIterator, Less>(first, last, Less());
}

}
#endif
