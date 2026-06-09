# 解题思路
矩阵为n_rows * n_cols矩阵，并且1 <= n_rows, n_cols <= 10000，而操作flip&reset总的数目<=1000。
很明显直接遍历矩阵是会超时的，时间复杂度O(n_rows  *n_cols * n), n为操作数目。
此题中操作数远小于矩阵规模，可以将其看做稀疏矩阵，只对有操作过的位置进行记录与处理，时间复杂度将远远降低，约为O(n^2 * log(n)),(忽略随机取值取过的情况)。
### flip
```
vector<int> flips; //已经翻转过的位置
```
1. 首先，进行降维，将二维矩阵降为一维矩阵
   对于二维矩阵中任意一个点[i,j]映射为一维矩阵中[k],它们之间转换关系如下：
   k = i * n_cols + j
   i = k / n_cols
   j = k % n_cols
2. 取随机值 
   利用rand()函数取随机值
3. 拒绝采样
   采用二分法搜索flips判断取到的随机值是否已经取过，如果已经取过，则拒绝，否则得到结果
4. 将结果记录到flips，并维持好顺序
### reset
1. 清空flips

### c++代码
```
class Solution {
public:
    int rows, cols, tot;
    vector<int> flips;
    Solution(int n_rows, int n_cols) {
        rows = n_rows, cols = n_cols;
        tot = n_rows * n_cols;
        flips.clear();
    }

    bool FindRand(int r) {
        int l = 0, h = flips.size();
        while(l < h) {
            int m = (l + h) / 2;
            if(flips[m] == r) return true;
            else if(flips[m] > r) h = m;
            else l = m + 1;
        }
        return false;
    }    

    void AddFlip(int r) {
        flips.push_back(r);
        int i = flips.size() - 1;
        for(; i > 0; i--) {
            if(flips[i] < flips[i-1]) {
                swap(flips[i], flips[i-1]);
            }
        }
    }

    vector<int> flip() {
        vector<int> result;

        while(1) {
            int r = rand() % tot;
            if(!FindRand(r)) {
                result.push_back(r/cols);
                result.push_back(r%cols);
                AddFlip(r);
                break;
            }
        }
        //printf("%d %d\n", result[0], result[1]);
      
        return result;

    }
    
    void reset() {
        flips.clear();
    }
};
```
