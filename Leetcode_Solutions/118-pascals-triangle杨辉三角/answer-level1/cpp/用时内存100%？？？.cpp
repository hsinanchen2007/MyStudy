### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int> > t;
        for(int i=1;i<numRows+1;++i){
            vector<int> tt(i);
            t.push_back(tt);
        }
        for(int i=0;i<numRows;++i){
            for(int j=0;j<=i;++j){
                if(j==0||j==i) t[i][j]=1;
                if(i>0&&j>0&&j<i)t[i][j]=t[i-1][j-1]+t[i-1][j];
            }
        }
        return t;

    }
};
```