### 解题思路
此处撰写解题思路
很简单的一道题，就是一次遍历，两两比较，不同的则修改靠前的元素，最后只返回前面的元素被修改的个数即可
### 代码

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator it;
        int size = nums.size();
        if(size==0) return 0;
        if(size==1) return 1;
        int j = 0,i=1;
        while(j<=size-2){
            if(nums[j]!=nums[j+1]){
                nums[i] = nums[j+1];
                i++;
                j++;
            }else j++;
        }
        return i;
    }
};
```