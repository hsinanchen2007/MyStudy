### 解题思路
把反转后的数组添加到原数组后，再把原来的数组元素删除，双100%。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int hang, lie;
        hang = lie = matrix.size();
        for (int k=hang-1;k>=0;k--){
            for (int i=0;i<hang;i++){
                matrix[i].push_back(matrix[k][i]);
            }
        }
        vector <int> :: iterator it;
        for (int i=0;i<hang;i++){
            for (int j=0;j<lie;j++){
                it = matrix[i].begin();
                matrix[i].erase(it);
            }
        }
    }
};
```