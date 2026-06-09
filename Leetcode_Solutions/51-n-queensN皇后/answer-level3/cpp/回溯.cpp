### 解题思路
硬解出来了，先将n个'.'放进base里面，用来初始化，将可能的答案放到temp里面，有解了就直接放入v中。
写一个判断是否可行的函数，每次放的时候判断，不行则复位，当一行中都不能放的话则返回到上一层，此时上一层的数据要初始化。
加一个pos数据，记录每行遍历到的位置，越界了则复位为0，其上一层+1，注意要将上一层的temp也复位。当pos[0]越界了，则说明已经遍历完了。

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> v;
        vector<string> temp(n);
        vector<int> pos(n);

        string base;
        for (int i=0; i<n; i++) base += '.';
        // 初始化
        for (int i=0; i<n; i++)
            temp[i] = base;
        
        //n*n循环
        for (int i=0; i<n; i++) {
            for (int j=pos[i]; j<n; j++) {
                temp[i][j] = 'Q';
                if (isok(n, temp)) {
                    if (i == n-1) {
                        v.push_back(temp);
                        temp[i][j] = '.';
                        pos[i]++;
                    } else break;
                } else {
                    temp[i][j] = '.';
                    pos[i]++;
                }
            }
            if (pos[i] == n) {
                pos[i] = 0;
                i--;
                if (i<0) break;
                pos[i]++;
                temp[i] = base;
                i--;
            }
        }
        return v;
    }

private:
    bool isok(int n, vector<string> v) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (v[i][j] == 'Q') {
                    for (int k=1; k<n; k++) {
                        if (i+k<n) {
                            if (v[i+k][j] == 'Q') return false;
                        }
                        if (j+k<n) {
                            if (v[i][j+k] == 'Q') return false;
                        }
                        if (i+k<n && j+k<n) {
                            if (v[i+k][j+k] == 'Q') return false;
                        }
                        if (i+k<n && j-k>=0) {
                            if (v[i+k][j-k] == 'Q') return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
```