### 解题思路
此处撰写解题思路
[1,2,3]      [1,4,7]      [7,4,1]
[4,5,6]  ==> [2,5,8]  ==> [8,5,2]
[7,8,9]      [3,6,9]      [9,6,3]

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int size = matrix.size() - 1;
		// Rota(45)
		for (int x = 0; x <= size; x++) 
			for (int y = x ; y <= size;y++) {
				int tmp = matrix[x][y];
				matrix[x][y] = matrix[y][x];
				matrix[y][x] = tmp;
			}
		
		//Rota(180)
		for (int x = 0; x <= size; x++)
			for (int y = 0; y <= size / 2;y++) {
				int tmp = matrix[x][y];
				matrix[x][y] = matrix[x][size-y];
				matrix[x][size-y] = tmp;
			}
    }
};
```