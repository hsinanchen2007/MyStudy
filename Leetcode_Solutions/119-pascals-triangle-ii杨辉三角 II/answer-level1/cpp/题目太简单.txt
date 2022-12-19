### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int> > t;
        for(int i=1;i<=rowIndex+1;++i){
            vector<int> tt(i);
            t.push_back(tt);
        }
        for(int i=0;i<rowIndex+1;++i){
            for(int j=0;j<=i;++j){
                if(j==0||j==i) t[i][j]=1;
                if(i>0&&j<i&&j>0) t[i][j]=t[i-1][j-1]+t[i-1][j];
            }
        }
        return t[rowIndex];
    }
};
```