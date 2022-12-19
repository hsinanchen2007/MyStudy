![QQ图片20191022161953.png](https://pic.leetcode-cn.com/eb7a8002c9537d959236b1211dcd3a80328c0a66a61409fc22e841bd03b73ac5-QQ%E5%9B%BE%E7%89%8720191022161953.png)

```
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n=hours.size();
        int tmp=0;
        vector<int> pos(n+2,-1);
        pos[0]=0;
        int res=0;
        for(int i=0,i1=1;i<n;++i,++i1)
        {
            tmp+=(hours[i]>8?1:-1);

            if(tmp>0)
            {
                res=i1;
            }
            else
            {
                if(pos[1-tmp]>=0)
                {
                    res=max(res,i-pos[1-tmp]);
                }
                if(pos[-tmp]==-1)
                {
                    pos[-tmp]=i;
                }
            }
        }

        return res;
        
    }
};
```
