注意到题目要求返回结果要排序，于是我们可以从最小的和入手。
当选的k块木板都是短板，那么此时的长度和为k * shorter。
把这个和放进res以后，我们考虑拿出一块短板，放入一块长板。
这时，长度和增加了（longer - shorter）。
这样不断换长板直到k块木板都是长板。

```
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k==0) return{};
        if(k==1) return {shorter,longer};
        if(shorter==longer) return {k * shorter};

        int sst = k * shorter;
        int d = longer - shorter;

        vector<int> res;
        res.push_back(sst);

        while(k-->0){
            sst += d;
            res.push_back(sst);
        }



        return res;
    }
};
```
