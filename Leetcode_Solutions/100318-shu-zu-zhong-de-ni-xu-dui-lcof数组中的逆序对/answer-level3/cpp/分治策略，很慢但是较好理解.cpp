### 解题思路
思路速度很慢，但是较好理解。
1. 将数组一分为二。
-    将两部分x与y分别排序。
-    使用双指针，如果x[i]>y[j]，则x中的每一个元素与y[j]皆构成逆序对，res+=x.size()-i，j++，否则i++。
2. 对于x与y分别进行递归操作，直至问题规模为2，此时若构成逆序对，则res++。

### 代码

```cpp
class Solution {
public:
    int res=0;
    void deal(vector<int>& nums,int s,int m,int f){
        if(s==m){
            if(nums[s]>nums[f])
                res++;
            return;
        }
        vector<int> x,y;
        for(int i=s;i<=m;i++)
            x.push_back(nums[i]);
        for(int i=m+1;i<=f;i++)
            y.push_back(nums[i]);
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        int i=0,j=0;
        while(i<x.size()&&j<y.size())
            if(x[i]>y[j]){
                res+=x.size()-i;
                j++;
            }
            else
                i++;
        deal(nums,s,(s+m)/2,m);
        deal(nums,m+1,(m+1+f)/2,f);
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        deal(nums,0,(nums.size()-1)/2,nums.size()-1);
        return res;
    }
};
```