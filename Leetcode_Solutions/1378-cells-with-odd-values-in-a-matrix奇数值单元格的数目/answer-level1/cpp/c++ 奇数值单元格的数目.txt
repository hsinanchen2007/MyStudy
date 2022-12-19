### 解题思路
利用两个一维数组 `rows[n] cols[m]` 记录 `indices` 中行和列出项的次数，然后对于 `i` 行 `j` 列判断 `rows[i] + cols[j]` 是否为奇数。
![图片.png](https://pic.leetcode-cn.com/717ee6a64028c00fc133dd23d148a2f3eb68778fe48982aedf4d9ade2609ea7e-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        int rows[n] = {0};
        int cols[m] = {0};
        for(auto indice : indices){
            rows[indice[0]] ++;
            cols[indice[1]] ++;
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j < m; j++){
                if((rows[i]+cols[j]) % 2)
                    res += 1;
            }
        }
        return res;
    }
};
```