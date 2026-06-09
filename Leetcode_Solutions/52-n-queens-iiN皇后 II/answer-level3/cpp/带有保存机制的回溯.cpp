### 解题思路
![微信截图_20200227215156.png](https://pic.leetcode-cn.com/811785af9de4e555a8066f55c3c7f9d4805466b7ce175328c8ebd31bb4670e27-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200227215156.png)

逐行或者逐列填入皇后，若合法则继续添加，不合法则回到上一步的状态。在边界（N皇后放置完毕）时存储进行结果的保存。

### 代码

```cpp
class Solution {
public:
	int N;
	vector<int> row;
	vector<int> col;
	vector<vector<int> > queens;
    int count = 0;
	int X[4] = {1, 1, -1, -1};
	int Y[4] = {1, -1, -1, 1}; //用于检查对角线是否合法

	void solveq(int ro, int co){
		if(ro == N - 1){//边界
			for(int i = 0; i < N; i++){
				if(col[i] == 0 && judge(ro, i)){
					queens[ro][i]++;
					count++; //保存结果
					queens[ro][i]--;
					return; //solved
				}
			}
		}
		else{
			for(int i = 0; i < N; i++){
				if(col[i] == 0 && judge(ro, i)){
					row[ro]++; col[i]++;
					queens[ro][i]++; //填入皇后

					solveq(ro + 1, co); //执行递归

					queens[ro][i]--;
					row[ro]--; col[i]--; //回溯
				}
			}
		}
	}

	bool judge(int ro, int co){//判断当前行列是否合法
		if(ro < 0 || co < 0 || ro >= N || co >= N){
			return false;
		}
		if(row[ro] == 0 && col[co] == 0){
			for(int i = 0; i < 4; i++){//4条斜线的检查
				int nowi = ro;
				int nowj = co;
				nowi += X[i];
				nowj += Y[i];
				while(nowi >= 0 && nowi < N && nowj >= 0 && nowj < N){
					if(queens[nowi][nowj] != 0){
						return false;
					}
					nowi += X[i];
					nowj += Y[i];
				}
			}
		}
		return true;
	}

    int totalNQueens(int n) {
    	N = n;
    	row.resize(N);
    	col.resize(N);
    	fill(row.begin(), row.end(), 0);
    	fill(col.begin(), col.end(), 0);

    	queens.resize(N);
    	for(auto& q: queens){
    		q.resize(N);
    	}
    	for(int i = 0; i < N; i++){
    		for(int j = 0; j < N; j++){
    			queens[i][j] = 0;
    		}
    	}
    	solveq(0, 0);//从原点开始遍历
    	return count;
    }
};
```