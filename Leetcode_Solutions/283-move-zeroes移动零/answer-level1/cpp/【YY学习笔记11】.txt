### 1.解题思路
采用双指针做法，本题可以理解为在原数组上进行一个更新：遇到非0数就将其更新到数组前面，遇到0就跳过，最后统一在末尾添加0。
### 2.知识点
双指针的用法。
### 3.感悟
我觉得现在用双指针能比最开始的时候熟练很多，果然还是熟能生巧，刷题刷起来！
### 代码

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //在原数组上进行一个更新：遇到非0数就将其更新到数组前面，遇到0就跳过，最后统一在末尾添加0。
        //使用双指针，其中i指向：更新的位置；j指向：非0元素。
        int i=0,j=0;
        while(i<nums.size()&&j<nums.size()){
            if(nums[j]==0){
                j++;
            }
            else{
                nums[i]=nums[j];
                i++;
                j++;
            }
        }
        for(int a=i;a<nums.size();a++){
            nums[a]=0;
        }
    }
};
```