

### 解题思路
执行用时 :20 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :10.8 MB, 在所有 C++ 提交中击败了100.00%的用户

首先想到循环遍历，但是不知道行列数目具体有多少怎么办呢？
使用**foreach**循环，
外层数组是使用``` <vector><int> ```类型
内层数组使用``` int ```类型
遍历一遍结果就出来了

### 代码

```cpp
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int s=0;
        for(vector<int> i : grid)
        {
            for(int y : i)
            {
                if(y<0)s++;
            }
        }
        return s;
    }
};
```