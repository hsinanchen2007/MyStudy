### 解题思路
1、上下180翻转
2、沿主对角线翻转

### 代码

```cpp
class Solution {
public:
void rotate(vector<vector<int> >& matrix) {
    int n = matrix.size();
    int i = 0;
    int j = matrix.size() - 1;
    while(i < j){ //上下180度翻转
        swap(matrix[i], matrix[j]);
        i++;
        j--;
    }
    
    for(int i = 0; i < matrix.size(); i++){ //主对角线翻转
        for(int j = i; j < matrix[0].size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
};
```