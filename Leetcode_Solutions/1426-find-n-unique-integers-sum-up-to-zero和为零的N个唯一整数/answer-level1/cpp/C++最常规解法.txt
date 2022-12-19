class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>p(n);
        if(n%2==1)//n为奇数时不需要分正负数进行赋值，可以节约大量时间
        {
        for(int i=0;i<n;i++)
        p[i]=i-n/2;
        }
        else 
        {
            for(int i=0;i<n/2;i++)
            p[i]=i+1;
            for(int i=n/2;i<n;i++)
            p[i]=-(i-n/2+1);
        }
        return p;
    }
};