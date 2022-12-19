优化了下别人的题解，当K较大时减少一些计算量

```
class Solution {
public:
    int superEggDrop(int K, int N) {
        if(K==1||N==1)return N;

        vector<int> res(K,3);
        res[0]=2;
        int res0=2;
        while(res[min(K,res0)-1]<N)
        {
            for(int i=min(K-1,res0);i>0;--i)
            {
                if(i==res0)
                {
                    res[i]=2*res[i-1]+1;
                }
                else
                {
                    res[i]+=res[i-1]+1;
                }
            }
            res[0]++;
            res0=res[0];
        }
        return res0;
    }
};
```
