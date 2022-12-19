### 解题思路
也可以采用迭代实现，关键在于找到旋转点之间的坐标关系。

### 代码

```cpp
class Solution {
private:
    void recursiveRotate(vector<vector<int>>& matrix, int startpos, int size){
        if(size <= 1) return;
        int endpos = startpos + size - 1;
        for(int i=startpos; i < endpos; i++){
            int temp = matrix[startpos][i];
            matrix[startpos][i] = matrix[endpos - (i -startpos)][startpos];
            matrix[endpos-(i -startpos)][startpos] = matrix[endpos][endpos-(i -startpos)];
            matrix[endpos][endpos-(i -startpos)] = matrix[i][endpos];
            matrix[i][endpos] = temp;
        }
        recursiveRotate(matrix, startpos+1, size-2);
    }
public: 
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        recursiveRotate(matrix, 0, N);
    }
};
```