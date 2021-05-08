#pragma once

#include "sort.h"
#include "../unsorted_sequence_table.h"

namespace structures
{

	/// <summary> Triedenie Heap sort. </summary>
	/// <typeparam name = "K"> Kluc prvkov v tabulke. </typepram>
	/// <typeparam name = "T"> Typ dat ukladanych v tabulke. </typepram>
	template <typename K, typename T>
	class HeapSort : public Sort<K, T>
	{
	public:
		/// <summary> Utriedi tabulku triedenim Heap sort. </summary>
		/// <param name = "table"> NonortedSequenceTable, ktoru ma utriedit. </param>
		void sort(UnsortedSequenceTable<K, T>& table) override;
		void sortByCustomKey(UnsortedSequenceTable<K, T>& table);
	};

	template<typename K, typename T>
	inline void HeapSort<K, T>::sort(UnsortedSequenceTable<K, T>& table)
	{
		bool swapping;
		for (int i = 1; i < (int)table.size(); i++) {
			int current = i;
			do {
				swapping = false;
				int father = (current - 1) / 2;
				if ((current > 0) && (table.getItemAtIndex(current).getKey() > table.getItemAtIndex(father).getKey())) {
					table.swap(current, father);
					current = father;
					swapping = true;
				}
			} while (swapping);
		}
		for (int i = (int)table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int current = 0;
			do {
				swapping = false;
				int max;
				int left = current * 2 + 1;
				int right = current * 2 + 2;
				if (left < i && right < i)
					max = table.getItemAtIndex(left).getKey() > table.getItemAtIndex(right).getKey() ? left : right;
				else
					max = left < i ? left : right;
				if (max < i && table.getItemAtIndex(max).getKey() > table.getItemAtIndex(current).getKey()) {
					table.swap(max, current);
					current = max;
					swapping = true;
				}
				//notify();
			} while (swapping);
		}
		//throw std::exception("HeapSort<K, T>::sort: Not implemented yet.");
	}

	template<typename K, typename T>
	inline void HeapSort<K, T>::sortByCustomKey(UnsortedSequenceTable<K, T>& table)
	{
		bool swapping;
		for (int i = 1; i < (int)table.size(); i++) {
			int current = i;
			do {
				swapping = false;
				int father = (current - 1) / 2;
				if ((current > 0) && (*table.getItemAtIndex(current).getKey() > *table.getItemAtIndex(father).getKey()))
				{
					table.swap(current, father);
					current = father;
					swapping = true;
				}
			} while (swapping);
		}
		for (int i = (int)table.size() - 1; i > 0; i--) {
			table.swap(0, i);
			int current = 0;
			do {
				swapping = false;
				int max;
				int left = current * 2 + 1;
				int right = current * 2 + 2;
				if (left < i && right < i)
					max = *table.getItemAtIndex(left).getKey() > *table.getItemAtIndex(right).getKey() ? left : right;
				else
					max = left < i ? left : right;
				if (max < i && *table.getItemAtIndex(max).getKey() > *table.getItemAtIndex(current).getKey()) {
					table.swap(max, current);
					current = max;
					swapping = true;
				}
				notify();
			} while (swapping);
		}
	}
}
