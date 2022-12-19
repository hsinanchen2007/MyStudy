### 解题思路
这个题目过于简单了，就是创建一个指针new_idx，然后遍历数组，
如果nums[i] != val，那么nums[new_idx++] = nums[i];
否则，继续遍历，这样i >= new_idx。
所以使用i的元素覆盖new_idx部分的元素也没关系，因为已经访问过了。

### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size(), new_idx = 0;
        for(int i = 0; i < len; ++i){
            if(nums[i] != val){
                nums[new_idx] = nums[i];
                new_idx++;
            }
        }
        return new_idx;
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 6.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户