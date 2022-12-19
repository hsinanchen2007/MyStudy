### 解题思路
利用vector性质 参考别人写的
对索引操作，边比较边导入，最后返回索引长度 
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::size_type nSize = nums.size();
        if (nSize <= 1){
            return nSize;
        }
        vector<int>::size_type p = 0;
        for (vector<int>::size_type i = 1; i < nSize; i++){
            if (nums[i] != nums[p]) {
                nums[++p] = nums[i];
            }
        }
        return p + 1;
    }
};
```