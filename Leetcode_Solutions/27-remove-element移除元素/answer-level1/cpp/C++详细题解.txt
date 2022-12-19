题目描述不允许使用额外的数组空间，所以只能在原数组上操作。

我们使用两个指针，一个快指针 i 和一个慢指针 k 。i 每次移动一步，而 k 只在添加新的被需要的值时才移动一步。

因为我们的新数组的长度会小于等于旧数组，调用者在调用函数时根据返回的长度，它会打印出数组中该长度范围（k）内的所有元素。因此，范围外的元素不会输出。
```
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); ++ i)
        {
            if(nums[i] != val)
            {
                nums[k] = nums[i];
                ++ k;
            }
        }
        return k;
    }
};
```