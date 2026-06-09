`188ms` `20.6MB`
记录每个奇数与前一个奇数位置的差值，计算`a[i]*a[i+k]`乘积的和。
```
#include "Solution1248.h"
#include<vector>
using namespace std;

class Solution1248 {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> a;
        int pre = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                a.push_back(i-pre);
                pre = i;
            }
        }
        a.push_back(nums.size()-pre);
        int ans = 0;
        for(int i=0;i+k<a.size();i++){
            ans += a[i]*a[i+k];
        }
        return ans;
    }
};
```
