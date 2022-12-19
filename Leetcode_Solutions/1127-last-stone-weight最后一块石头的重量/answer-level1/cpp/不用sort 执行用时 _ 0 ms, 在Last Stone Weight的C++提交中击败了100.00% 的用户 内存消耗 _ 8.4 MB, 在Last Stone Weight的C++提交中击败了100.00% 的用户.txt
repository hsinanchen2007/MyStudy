__不用排序，只需要不断找出第二最大值，到最后第二最大值会变为零__
```
class Solution {
public:
    auto findMaxStone(vector<int>& stones){
        auto max=max_element(stones.begin(),stones.end());
        return max;
    }
    int lastStoneWeight(vector<int>& stones) {
        AGAIN:
        int x2;
        auto x=findMaxStone(stones);
        x2=*x;
        *x=0;
        auto y=findMaxStone(stones);
        if(*y==0)
            return x2;
        if((x2)!=*y)
        {
            if(max(x2,*y)==x2)
            {
                *x=x2-*y;
                *y=0;
            }
            *y=*y-x2;
        }
        *y=0;
        goto AGAIN;
    }
};

```