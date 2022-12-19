### 解题思路
和杨辉三角1解题思路一样，就是构建杨辉三角，返回最后一行就行

### 代码

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> a(rowIndex+1);
        for(int i=0;i<=rowIndex;i++){
            for(int j=0;j<i+1;j++)
            {
                if(j==0||j==i)
                    a[i].push_back(1);
                else{
                    a[i].push_back(a[i-1][j]+a[i-1][j-1]);
                }
            }
        }
        return a[rowIndex];
    }
};
```