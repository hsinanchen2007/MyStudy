![QQ图片20191023141642.png](https://pic.leetcode-cn.com/072f8e3ccc91765bf6844e31083986eff95c6b11895cda013d3a57ddb7c24eb5-QQ%E5%9B%BE%E7%89%8720191023141642.png)


```
class StockSpanner {
public:
    stack<pair<int,int>> tmp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res=1;

        while(!tmp.empty())
        {   
            auto tmp0=tmp.top();
            if(tmp0.first<=price)
            {
                res+=tmp0.second;
                tmp.pop();
            }
            else
            {
                break;
            }
        }
        tmp.emplace(pair<int,int>(price,res));
        return res;
    }
};
```
