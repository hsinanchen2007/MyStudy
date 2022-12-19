### 解题思路
执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :8.3 MB, 在所有 C++ 提交中击败了100.00%的用户

观察发现
(1)原坐标(i, j)的元素顺时针旋转90度到达(j, n - i -1)的位置。
(2)旋转4次，就会回到原来的位置，所以需要找到每组4个元素的第一个进行4次旋转即可，不要重复同一组内的旋转；
(3)对角线以及以下的元素(即纵坐标小于等于横坐标)，如果旋转一次，落到对角线以上(即纵坐标大于横坐标)，就是每组的第一个元素

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return;
        }
        int n = matrix.size();

        
        //只看对角线及以下的元素
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                //进行一次顺时针旋转
                int p = j;
                int q = n - 1 - i;
                //如果转到对角线以上了
                if (q > p) {
                    int old_value = matrix[i][j];
                    //同一组内的元素依次顺时针旋转一次
                    while (p != i || q != j) {
                        int new_value = matrix[p][q];
                        matrix[p][q] = old_value;
                        old_value = new_value;
                        int old_p = p;
                        int old_q = q;
                        p = old_q;
                        q = n - 1 - old_p;
                    }
                    matrix[i][j] = old_value;
                }
            }
        }
    }
};
```