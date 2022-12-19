### 解题思路
此处撰写解题思路
本来用f数组写着写着成了max1max2max3了。。。。。

### 代码

```cpp
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int sum=0;
        int ans[50009];
        int f[50009][10];
        int maxn1=0;
        int maxn2=0;
        int maxn3=0;
        int i1[50009];
        int i2[50009];
        int i3[50009];
        int max1[50009];
        int max2[50009];
        int max3[50009];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans[i]=sum;
        }
        for(int i=0;i<nums.size();i++){
            if(i<k-1)
                f[i][1]=0;
            else{
                if(ans[i]-ans[i-k+1]+nums[i-k+1]>maxn1){
                    i1[i]=i-k+1;
                    max1[i]=ans[i]-ans[i-k+1]+nums[i-k+1];
                    maxn1=ans[i]-ans[i-k+1]+nums[i-k+1];
                }
                else{
                    i1[i]=i1[i-1];
                    max1[i]=max1[i-1];
                }
            }
            if(i<2*k-1)
                f[i][2]=0;
            else{
                if(ans[i]-ans[i-k+1]+nums[i-k+1]+max1[i-k+1-1]>maxn2){
                    i2[i]=i-k+1;
                    max2[i]=ans[i]-ans[i-k+1]+nums[i-k+1]+max1[i-k+1-1];
                    maxn2=ans[i]-ans[i-k+1]+nums[i-k+1]+max1[i-k+1-1];
                }
                else{
                    i2[i]=i2[i-1];
                    max2[i]=max2[i-1];
                }
            }
            if(i<3*k-1)
                f[i][3]=0;
            else{
                if(ans[i]-ans[i-k+1]+nums[i-k+1]+max2[i-k+1-1]>maxn3){
                    i3[i]=i-k+1;
                    max3[i]=ans[i]-ans[i-k+1]+nums[i-k+1]+max2[i-k+1-1];
                    maxn3=ans[i]-ans[i-k+1]+nums[i-k+1]+max2[i-k+1-1];
                }
                else{
                    i3[i]=i3[i-1];
                    max3[i]=max3[i-1];
                }
            }
        }
        vector<int>p;
        //for(int i=0;i<nums.size();i++)
        //p.push_back(max3[i]);
        p.push_back(i1[i2[i3[nums.size()-1]-1]-1]);
        p.push_back(i2[i3[nums.size()-1]-1]);
        p.push_back(i3[nums.size()-1]);
        return p;
    }
};
```