建立一个和数列sums_array, 其中sums_array[i]等于sum(nums[0:i+1])。然后用merge sort对这个sums_array进行排序，在排序过程中，每次将left和right列表merge前，为left中的每一个元素确定right中符合条件的值的范围。也就是说在right中设两个指针lo和up，其中lo指向right中第一个使right[lo] - left[i] >= lower的元素，而up指向right中最后一个使right[up] - left[i] <= upper的元素，将up-lo加到最后的结果上即可。
```
class Solution:
    res = 0
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        length = len(nums)
        if length == 0:
            return 0
        sums_array = [0]
        s = 0
        for i in range(length):
            s += nums[i]
            sums_array.append(s)
        print('sums_array: ', sums_array)
        idx_array = list(range(length+1))
        self._merge_sort(sums_array, idx_array, lower, upper, 0, length)
        return self.res

    def _merge(self, sums_array, idx_array, lower, upper, left, mid, right):
        tmp = idx_array[left:right+1]
        lo = mid+1
        for i in range(left, mid+1):
            lval = sums_array[tmp[i-left]]
            lo_val = sums_array[tmp[lo-left]]
            while lo <= right and sums_array[tmp[lo-left]] - lval < lower:
                lo += 1
            if lo > right:
                break
            up = lo
            while up <= right and sums_array[tmp[up-left]] - lval <= upper:
                up += 1
            self.res += (up - lo)

        l, r = left, mid+1
        for i in range(left, right+1):
            if r > right:
                idx_array[i] = tmp[l - left]
                l += 1
            elif l > mid:
                idx_array[i] = tmp[r - left]
                r += 1
            elif sums_array[tmp[l - left]] <= sums_array[tmp[r - left]]:
                idx_array[i] = tmp[l - left]
                l += 1
            elif sums_array[tmp[l - left]] > sums_array[tmp[r - left]]:
                idx_array[i] = tmp[r - left]
                r += 1
        
    def _merge_sort(self, sums_array, idx_array, lower, upper, left, right):
        if left >= right:
            return
        mid = left + (right - left) // 2
        self._merge_sort(sums_array, idx_array, lower, upper, left, mid)
        self._merge_sort(sums_array, idx_array, lower, upper, mid+1, right)
        self._merge(sums_array, idx_array, lower, upper, left, mid, right)
```
