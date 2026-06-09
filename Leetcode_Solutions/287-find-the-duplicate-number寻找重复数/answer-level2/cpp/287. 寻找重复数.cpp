### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len=nums.size();
        int left=0, right=len-1;
        while(left<right){
            int cnt=0, mid=(left+right)>>1;
            for(int i=0;i<len;i++){
                if(nums[i]<=mid) cnt++;
            }
            if(cnt<=mid){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }
};
```