### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findMagicIndex(vector<int>& nums) {
        return foo(nums,0,nums.size()-1);
    }
    
    int foo(vector<int>& nums,int left,int right){
        if(left > right) return -1;
        
        int mid = left + (right - left) / 2;
        int res = -1;
        if(nums[mid] == mid){
            res = mid;
            int temp = foo(nums,0,mid-1);
            return temp == -1?res:temp;
        }
        else if(nums[mid] > mid){
            int temp1 = foo(nums,left,mid-1);
            if (temp1 != -1) return temp1;
            int temp2 = foo(nums,nums[mid],right);
            return temp2;
        }
        else{
            int temp1 = foo(nums,left,nums[mid]);
            if(temp1 != -1) return temp1;
            int temp2 = foo(nums,mid+1,right);
            return temp2;
        }
    }
};
```