方法就是上一个杨辉三角的方法，没想到直接0ms，吃惊
![QQ截图20200223170658.png](https://pic.leetcode-cn.com/6fad0680bdb9e567528b206df24a71d040e2284d2c34cea4c71577e494868684-QQ%E6%88%AA%E5%9B%BE20200223170658.png)


```
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> feby(rowIndex+1);
        for(int i=0;i<=rowIndex;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(j==0 || j==i)
                    feby[i].push_back(1);
                else
                    feby[i].push_back(feby[i-1][j-1]+feby[i-1][j]);
            }
        }
        return feby[rowIndex];
    }
};
```
