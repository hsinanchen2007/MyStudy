![QQ图片20190923184109.png](https://pic.leetcode-cn.com/82fe59bfcfe75979971c4a7d62becb40a14296ef18562e52e77c5d2958ea020c-QQ%E5%9B%BE%E7%89%8720190923184109.png)

```
class Solution {
public:
    int brokenCalc(int X, int Y) {
        if(X>=Y)return X-Y;
        vector<int> q;
        int t=Y;
        while(t>X)
        {
            q.emplace_back(t);
            t=(t+1)/2;
        }
        int res=X-t;
        for(int i=q.size()-1;i>=0;--i)
        {
            res+=(t*2-q[i]+1);
            t=q[i];
        }
        return res;
    }
};
```
