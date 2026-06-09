### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len=nums.size();
        if(len==0) return 0;
        int dl[10001];
        for(int i=1;i<len;i++){ //对应的每一个状态
            dl[i]=1;
            for(int j=0;j<i;j++){ 
                if(nums[i]>nums[j]) dl[i]=max(dl[i],dl[j]+1);
            }
        }
        for(int i=1;i<len;i++){
            dl[i]=max(dl[i],dl[i-1]);
        }
        return dl[len-1];
    }
};
```