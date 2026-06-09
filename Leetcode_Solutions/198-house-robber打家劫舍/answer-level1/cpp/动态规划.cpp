1. 一个数，f1=N1=max(f0,f(-1)+N1),令f(-1)=0,f(0)=0
2. 两个数，f2=max(N1,N2)=max(f1,f0+N2)
3. 三个数1）若第三次偷，则f3=N3+f1;2)若第三次不偷，则f3=f2。因此，f3=max(f2,f1+N3)
4. 同理fn=max(f(n-1),f(n-2)+Nn)
``` C++
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        int onePre=0,twoPre=0;//记录前一次、前两次的最大值
        int res=0;
        for(int i=1;i<=nums.size();i++)
        {
            res=max(onePre,twoPre+nums[i-1]);
            twoPre=onePre;
            onePre=res;
        }
        return res;
    }
};
```