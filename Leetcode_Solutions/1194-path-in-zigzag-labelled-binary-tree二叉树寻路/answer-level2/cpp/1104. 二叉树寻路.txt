![QQ图片20190926115321.png](https://pic.leetcode-cn.com/190126dbe620459bd759bdb5a66d1a1fb60e31c75672d15addfc7db33e7b4c53-QQ%E5%9B%BE%E7%89%8720190926115321.png)
找到通项公式即可

```
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int base=1;
        int count=0;
        while(label>=base)
        {
            base<<=1;
            ++count;
        }
        vector<int> res(count);
        res[count-1]=label;
        for(int i=count-2;i>0;--i)
        {
            res[i]= (1<<i)*3-1-(res[i+1]>>1);
        }
        res[0]=1;
        return res;
    }
};
```
