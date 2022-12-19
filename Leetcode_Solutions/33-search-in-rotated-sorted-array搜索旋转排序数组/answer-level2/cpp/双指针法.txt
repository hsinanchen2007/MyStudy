### 解题思路
两个指针往中间走
### 代码

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        if(len==1){
            if(nums[len-1]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        int i,j;
        i=0;
        j=len-1;
        while(i<j){
            if(nums[i]==target)return i;
            if(nums[j]==target)return j;
            if(nums[i]>target){
                if(nums[j]<target){
                    return -1;
                }
                else{
                    j--;
                }
            }
            else{
                if(nums[i+1]>target){
                    return -1;
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};
```