### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            while(i<=j&&nums[i]%2==1)i++;
            while(i<=j&&nums[j]%2==0)j--;
            if(i<=j){
                int tmp;
                tmp=nums[i];
                nums[i]=nums[j];
                nums[j]=tmp;
                i++;
                j--;
            }
        }
        return nums;
    }
};
```