## 思路
先对数组排序，然后找出数组中间位置数，将数组分为两段，先从前半段取最后一个数放在原数组第一个位置，然后从后半段取最后一个数放在原数组第二个位置，这样保证第一个数小于第二个数，然后再从前半段取大数第二个数，放在原数组第三个位置，从后半段取倒数第二个数放在原数组第四个位置，这保证第三个数小于第二个数且小于第四个数，以此类推。

### 代码
时间复杂度：O(nlogn)
空间复杂度：O(n)
```c++
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int size = nums.size();
        vector<int> tmp(nums);
        int end = size-1, mid = (size + 1) / 2 - 1;
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < size; ++i) {
            nums[i] = i % 2 == 0 ? tmp[mid--] : tmp[end--];
        }
    }
};
```
