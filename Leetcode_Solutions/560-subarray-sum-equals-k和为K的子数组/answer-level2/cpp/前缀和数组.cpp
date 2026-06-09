### 解题思路
前缀和

### 代码

```cpp
class Solution {
public:
    //前缀和数组
    int presum[20010];
    int subarraySum(vector<int>& nums, int k) {
        presum[0]=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            presum[i+1]=presum[i]+nums[i];
            //cout<<presum[i+1]<<endl;
        }
        for(int i=0;i<=nums.size();i++){
            for(int j=0;j<i;j++){
                //cout<<i<<","<<j<<"  "<<presum[i]-presum[j]<<endl;
                if(presum[i]-presum[j]==k){
                    count++;
                }
            }
        }
        return count;
    }
};
```