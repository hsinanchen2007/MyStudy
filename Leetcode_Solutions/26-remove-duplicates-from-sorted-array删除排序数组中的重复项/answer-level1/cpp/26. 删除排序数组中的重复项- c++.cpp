### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
       
        int index=1;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[j-1]){
                nums[index++]=nums[j];
            }
                
        }
        return index;

      
    }
};
```
1）创建两个指针，一个目标数组的大小，另一个遍历数组。
2）如果该数组没有元素，那么直接返回0，否则执行3）。
3）该数组中有效元素个数至少是1，所以将有效元素个数index初始化为1。
4）向后遍历，如果当前元素和前一个元素不相同，就把角标为index的值赋值为当前元素，index自增。
5）返回index值，即有效元素个数。
nums[index++]----->nums[index]; index++;
