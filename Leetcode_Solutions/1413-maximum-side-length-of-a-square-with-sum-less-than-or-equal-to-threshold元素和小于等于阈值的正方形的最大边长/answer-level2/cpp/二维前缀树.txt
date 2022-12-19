### 解题思路
一维前缀树处理子数组和问题；二维前缀树处理矩阵问题；

二维前缀树：首先是构造二维前缀树：
![20180921215152309.png](https://pic.leetcode-cn.com/d3059dc82472537cdb96fd216d77b933e798afac5f968594ad2109158dbf26d2-20180921215152309.png)
其实递推公式就是：
preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] + mat[i][j] - preSum[i - 1][j - 1];
只不过这里面需要首先处理第一行，然后处理第一列；

其次就是使用，如何在O（1）的时间复杂度里面查找矩阵和？
![20180921215152309.png](https://pic.leetcode-cn.com/861acf2c7a6d37406a00fe2cb617a9c8229a2431f111307a878c2ae44700873b-20180921215152309.png)
preSum[x1][y1] - preSum[x0 - 1][y1] - preSum[x1][y0 - 1] + preSum[x0 - 1][y0 - 1];
但是这里需要注意X0Y0的位置，如果有一个为0，就不需要减去某一个额外项即可。

**二分:**
其实C++利用二维前缀和已经可以解决问题，但是可以用二分优化。
暴力解法中，从最大长度，遍历到最小长度；但是，实际上如果某个长度不行，那么大于它的肯定都不行，就不用遍历了；同理，如果某个长度可以，那么小于它的肯定都可以，是有**递推性质**的；

于是可以对长度进行二分查找；

### 代码

```cpp
class Solution {
public:
    int GetAns(vector<vector<int>>& preSum, int x0, int y0, int x1, int y1) {
		if (x0 == 0 && y0 == 0) {
			return preSum[x1][y1];
		}
		if (x0 == 0) {
			return preSum[x1][y1] - preSum[x1][y0 - 1];
		}
		if (y0 == 0) {
			return preSum[x1][y1] - preSum[x0 - 1][y1];
		}
        return preSum[x1][y1] - preSum[x0 - 1][y1] - preSum[x1][y0 - 1] + preSum[x0 - 1][y0 - 1];
    }
	void InitializePreSum(vector<vector<int>>& mat, vector<vector<int>>& preSum) 
	{
		preSum[0][0] = mat[0][0];
		for (int i = 1; i < mat[0].size(); i++) {
			preSum[0][i] = mat[0][i] + preSum[0][i - 1];
		}
		for (int i = 1; i < mat.size(); i++) {
			preSum[i][0] = mat[i][0] + preSum[i - 1][0];
		}
		for (int i = 1; i < mat.size(); i++) {
			for (int j = 1; j < mat[0].size(); j++) {
				preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] + mat[i][j] - preSum[i - 1][j - 1];
			}
		}
	}
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        if (mat.empty()) {
            return 0;
        }
		vector<vector<int>> preSum(mat.size(), vector<int> (mat[0].size(), 0));
		InitializePreSum(mat, preSum);
        int maxLength = min(mat.size(), mat[0].size());
		int minLength = 1;
		int mid = (maxLength + minLength)/2;
		int ans = 0;
		
		while(minLength <= maxLength) {
			bool flag = false;
			for (int k = 0; k + mid <= mat.size(); k++) {
                for (int j = 0; j + mid <= mat[0].size(); j++) {
                    if (GetAns(preSum, k, j, k + mid - 1, j + mid - 1) <= threshold) {
                        ans = max(ans, mid);
						flag = true;
						break;
                    }
                }
            }
			if (flag) {
				minLength  = mid+ 1;
			} else {
				maxLength = mid - 1;
			}
			mid = (maxLength + minLength)/2;
		}
        return ans;
    }
};
```