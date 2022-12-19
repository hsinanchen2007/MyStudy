### 递归法 ###
#### 思路 ####
- 比赛匹配显然是一个树状结构，引入变量`d`记录深度
- 把决赛时的深度设为`1`，其节点数为`pow(2, 1)`，无论`n`为多少，左右子树的第一支队伍分别为队伍`1`和队伍`2`
  - 于是，可以得到关系`1 + 2 == pow(2, 1) + 1`
- 更一般地，设左子树的第一支队伍为`i`，右子树的第一支队伍为`j`，则有`i + j == pow(2, d) + 1`
- 按照上述关系，自顶向下划分左右子树，直到`pow(2, d) == n`，将队伍的数字编号转化为字符串输出
#### 代码 ####
##### `d`标记深度 #####
```cpp []
class Solution {
public:
    string findContestMatch(int n) {
        return helper(n, 1, 1);
    }
    string helper(int& n, int i, int d) {
        if (pow(2, d) == n) return "(" + to_string(i) + "," + to_string(n + 1 - i) + ")";
        return "(" + helper(n, i, d + 1) + "," + helper(n, pow(2, d) + 1 - i, d + 1) + ")";
    }
};
```
```python3 []
class Solution:
    def findContestMatch(self, n: int) -> str:
        def helper(i = 1, d = 1):
            if 2**d == n: return "({},{})".format(i, n + 1 - i)
            return "({},{})".format(helper(i, d + 1), helper(2**d + 1 - i, d + 1))
        return helper()
```
##### `d`标记深度对应的节点数 #####
```cpp []
class Solution {
public:
    string findContestMatch(int n) {
        return helper(n, 1, 2);
    }
    string helper(int& n, int i, int d) {
        if (d == n) return "(" + to_string(i) + "," + to_string(n + 1 - i) + ")";
        return "(" + helper(n, i, d * 2) + "," + helper(n, d + 1 - i, d * 2) + ")";
    }
};
```
```python3 []
class Solution:
    def findContestMatch(self, n: int) -> str:
        def helper(i = 1, d = 2):
            if d == n: return "({},{})".format(i, n + 1 - i)
            return "({},{})".format(helper(i, d * 2), helper(d + 1 - i, d * 2))
        return helper()
```
#### 复杂度分析 ####
- 时间复杂度 $O(n)$，每支队伍只被访问 $1$ 次
- 空间复杂度 $O(\log n)$，二分递归最大深度为 $\log n$

