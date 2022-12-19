相对于从后往前遍历，多定义了两个int；

```
class Solution {
public:

    vector<int> getRow(int rowIndex) {
        vector<int> res;
        res.push_back(1);
        int tmp1 = 0;
        int tmp2 =1;
        for(int i = 0;i < rowIndex;i++)
        {
            for(int j = 0;j < i;j++)
            {
                tmp1 = res[j+1];
                res[j+1] = tmp2+res[j+1];
                tmp2 = tmp1;
            }
            res.push_back(1);
        } 
        return res;
    }
};
```
