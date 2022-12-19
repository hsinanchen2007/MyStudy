0ms
![image.png](https://pic.leetcode-cn.com/1b3b92ee0094344bdd377b36df01331edb14c9f3c0e66d2ebc51d3c8a7795f79-image.png)

```
class Solution {
public:
    vector<int> getRow(int numRows) {
        vector<int> res, help = {1,1};
        if(numRows >= 0)
            res.push_back(1);
        if(numRows >= 1)
            res.push_back(1);
        for(int i = 2; i <= numRows; i++){
            for(int j = 1; j < i; j++)
                res[j] += help[j-1];
            res.push_back(1);
            for(int j = 0; j < res.size()-1; j++)
                help[j] = res[j];
            help.push_back(1);
        }
        return res;
    }
};
```

