1.从后往前遍历，找到交换的节点
2.在后面的数字中找到比该数字大的数字中最小的那个，进行交换
3.再对后面的数字从小到大排序，但深入理解后发现reverse可以替代排序
4.若顺序排列，直接转置即可
本题的巧妙之处在于很多情况可以合并，所以最后的代码是很简单的
```
class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 1;
        for ( ; i > 0; --i)
            if (nums[i] > nums[i-1]) {
                int j = i;
                for ( ; j < n && nums[j] > nums[i-1]; ++j)
                    ;
                swap(nums[i-1], nums[j-1]);
                break;
            }
        reverse(nums.begin() + i, nums.end());
    }
};
```
