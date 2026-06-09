一开始还考虑a是否为0退化为一次函数，发现没必要，直接考虑2ax+b不变号的两个区间，分别存到两个vector里，如果是递减就reverse一下，最后两个merge。

4ms,直接sort是8ms.
```
class Solution {
public:
    int f(int x,int a,int b,int c){
        return a*x*x+b*x+c;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int>rec1,rec2;
        for(int i=0;i<nums.size();i++){
            if(-2*a*nums[i]<b)rec1.push_back(f(nums[i],a,b,c));
            else rec2.push_back(f(nums[i],a,b,c));
        }
        if(rec1.size()>1){
            if(rec1[0]>rec1[rec1.size()-1])reverse(rec1.begin(),rec1.end());
        }
        if(rec2.size()>1){
            if(rec2[0]>rec2[rec2.size()-1])reverse(rec2.begin(),rec2.end());
        }
        vector<int>ans(nums.size(),0);
        merge(rec1.begin(),rec1.end(),rec2.begin(),rec2.end(),ans.begin());
        return ans;
    }
};
```
