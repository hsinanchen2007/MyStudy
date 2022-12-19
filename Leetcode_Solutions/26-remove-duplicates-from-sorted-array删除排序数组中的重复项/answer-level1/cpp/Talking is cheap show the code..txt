### 解题思路
线性数据结构可以利用一快一慢指针来操作,注意数组越界
慢指针指向左边需要寻找相同的元素,快指针找到与慢指针不一样的元素;
loop:
当找到快指针找到与慢指针不一样的元素时候,将慢指针下一个元素替换成快指针指向的元素;
慢指针往右移动一位指向下一个要替换元素的索引;
快指针继续往右移动
end
返回 慢指针的索引加1
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int N = nums.size();
        if(N ==0) return 0;
        int j = 1;
        int k = 0;
        
        for (int i =0; i <N ,j< N;){
            if (nums[i]!=nums[j]){
                nums[i+1] = nums[j];
                i++;
                k = i;
            }
            j++;
        }
        return k+1;
    }
};
```