### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int dx[4] ={1, 1, 0, -1}; //three direction, right, right down, down, left down,
    int dy[4] ={0, 1, 1, 1};
    int longestLine(vector<vector<int>>& M)
    {
        if (M.empty()) {
            return 0;
        }
        int maxL{0};
        for (int r = 0; r < M.size(); r++) {
            for (int c = 0; c < M[0].size(); c++) {
                for(int d = 0; d < 4; d++) {
                    int length = 1;
                    DFS(M, r, c, d, length);
                    maxL = length > maxL? length : maxL;
                }
            }
        }
        // cout<< "----------"<< maxL;
        return maxL;
    }

    void DFS (vector<vector<int>>& M, int r, int c, int d, int& length)
    {
        if(M[r][c] == 0) {
            --length;
            return;
        }
        // cout << "r: "<< r << ", c: "<< c <<", length: " << length <<", direction: " << d << endl;
        int nextR = r + dy[d];
        int nextC = c + dx[d];
        if(nextR < M.size() && nextC < M[0].size() && nextC >=0) {
//            cout << "r: "<< nextR << ", c: "<< nextC << endl;
            DFS(M,nextR,nextC,d,++length);
        } else {
            return;
        }
    }
};
```