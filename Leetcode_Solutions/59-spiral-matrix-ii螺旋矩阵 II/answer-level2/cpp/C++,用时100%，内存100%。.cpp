### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/223fd643498cdeb378af44cb207c0b1570e5f8b7e16ab53886f2303c4954fb94-image.png)

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n<=0) {
            return {};
        }
        vector<vector<int>> res;
        int left = 0;
        int right = n -1;
        int up = 0;
        int down = n -1;
        for (int i = 0; i < n; i++) {
            vector<int> temp(n,0);
            res.emplace_back(temp);
        }
        
        int number = 0;
        while(number != n*n){
            for (int i = left; i <= right; i++) {
                res[up][i] = ++number;
            }
            up++;
            for (int i = up; i <= down; i++) {
                res[i][right] = ++number;
            }
            right--;
            for (int i = right; i >= left; i--) {
                res[down][i] = ++number;
            }
            down--;
            for (int i = down; i >=up; i--){
                res[i][left] = ++number;
            }
            left++;
        }
        return res;
    }
};

```