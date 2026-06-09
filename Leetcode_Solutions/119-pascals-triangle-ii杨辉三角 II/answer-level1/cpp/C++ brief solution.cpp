因为我们只需要返回第k行的结果，所以相比于前一题，我们不需要记录整个三角形的数，只需要对一行数组不断循环操作即可。

AC代码：
```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1,0);
        res[0]=1;
        for(int i=1;i<rowIndex+1;i++)
        {
            for(int j=i;j>=1;j--)
                res[j]+=res[j-1];
        }
        
        return res;
    }
};
```