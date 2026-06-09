### 解题思路
此处撰写解题思路
定义一个指针，从0位置开始，遇到不等于val的就赋值给指针所指位置上，然后指针加1.
### 代码

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int now_p = 0;
        if(nums.size()<=0)
            return 0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]!=val){
                nums[now_p]=nums[i];
                now_p++;
            }
        }
        return now_p;
        
    }
};
```