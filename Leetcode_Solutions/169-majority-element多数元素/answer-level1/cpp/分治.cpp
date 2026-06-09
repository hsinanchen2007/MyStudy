### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
     return majorityElement(nums, 0, nums.size() - 1);
    }
  int   majorityElement(vector<int>&nums,int lt,int rt)
    {
        if(lt==rt)return nums[lt];
        int mid=(rt-lt)/2+lt;
        int letft=majorityElement(nums,lt,mid);
        int right=majorityElement(nums,mid+1,rt);
        if(letft==right)return letft;
        int x=0;
        int j=0;
        for(int i=lt;i<=mid;i++)
        {
            if(letft==nums[i])x++;
        }
       for(int z=mid+1;z<=rt;z++)
       {
         if(right==nums[z])j++;
       }
       return x>j?letft:right;
    }
};
```