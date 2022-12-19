## 思路一：暴力
用二维矩阵表示图，1表示认识，0表示不认识。
如果在trust中存在[1,2]，则图中(1, 2)位置用 1 表示认识，且图中自己认识自己。如果存在一个列值都为1，而以这个列值为行号所在行中只有本身为1，则该列值即为法官，否则不存在。
### 代码
```
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (N == 0) {
            return -1;
        }
        //没有认识关系，则返回序号1
        if (trust.empty() || trust[0].size() == 0) {
            return 1;
        }
        vector<vector<int>> matrix(N+1, vector<int>(N+1, 0));//序号从1开始
        int row = trust.size();
        int index = -1;
        //1. 初始化图
        for (int i = 0; i < row; ++i) {
            matrix[trust[i][0]][trust[i][1]] = 1;
        }
        for (int i = 1; i <= N; ++i) {
            matrix[i][i] = 1;
        }
        //2. 遍历每一列
        for (int j = 1; j <= N; ++j) {
            int i;
            //遍历每一行
            for (i = 1; i <= N; ++i) {
                if (matrix[i][j] != 1) {
                    break;
                }
            }   
            //存在列值都为1的列         
            if (i > N) {
                int k;
                for (k = 1; k <= N; ++k) {
                    if (k != j && matrix[j][k] == 1) {
                        break;
                    }
                }              
                //存在一行中只有本身为1的行    
                if (k > N) {
                    index = j;                    
                }
            }
        }
        return index;            
    }
};
```

## 思路二：出度入度差
法官入度为N-1，出度为0
### 代码
```c++
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> g(N+1, 0);//入度-初度，初始值为0
        for (auto t : trust) {
            --g[t[0]];//出度增加，则和减1
            ++g[t[1]];//入度增加，则和加1
        }
        for (int i = 1; i <= N; ++i) {
            if (g[i] == N-1) {
                return i;
            }
        }
        return -1;            
    }
};
```


