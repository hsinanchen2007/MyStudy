## 一次编辑

> CC189 面试题 01.05
>
> 难度：
>
> - `中等`
>
> tags：
>
> - `编辑距离`
>
> -  `双指针`

## 题目描述

字符串有三种编辑操作:插入一个字符、删除一个字符或者替换一个字符。 给定两个字符串，编写一个函数判定它们是否只需要一次(或者零次)编辑。

**示例 1:**

```
输入: 
first = "pale"
second = "ple"
输出: True
```

**示例 2:**

```
输入: 
first = "pales"
second = "pal"
输出: False
```

------

## 思路：

### 1. 编辑距离求解

执行用时 :20 ms, 在所有 C++ 提交中击败了7.53%的用户

内存消耗 :11 MB, 在所有 C++ 提交中击败了100.00%的用户

可见，很慢，因为求解了很多冗余信息。

```cpp
class Solution {
public:
  bool oneEditAway(string first, string second) {
    int len1 = first.size(), len2 = second.size();
    if (abs(len1 - len2) > 1) return false;
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for (int i = 1; i <= len1; i++) dp[i][0] = i;
    for (int j = 1; j <= len2; j++) dp[0][j] = j;
    for (int i = 1; i <= len1; i++) {
      for (int j = 1; j <= len2; j++) {
        if (first[i-1] == second[j-1]) {
          dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1] + 1, dp[i-1][j] + 1));
        } else {
          dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i][j-1] + 1, dp[i-1][j] + 1));
        }
      }
    }
    return dp[len1][len2] <= 1;
  }
};
```



### 2. 双指针

执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户

内存消耗 :8.6 MB, 在所有 C++ 提交中击败了100.00%的用户

#### 算法：

首先判断两个字符串长度，相差大于一返回 `false`

双指针遍历两个字符串，同时记录编辑次数 `op_cnt`：

- 若 `first[i] == second[j]`，不需编辑，i，j 加一

- 若 `first[i] != second[j]`，分为三种情况：
  - `first[i] == second[j+1]`，那么 j++，op_cnt++
  - `first[i+1] == second[j]`，那么 i++，op_cnt++
  - 以上两种都不符合，那么使用替换操作，i++，j++，op_cnt++
  - 注意，一旦 `op_cnt > 1`，返回 `false`

遍历结束后，若仍有一方未走到结尾，且相差的长度 + op_cnt 大于 1，则返回 `false`

```cpp
class Solution {
public:
  bool oneEditAway(string first, string second) {
    int len1 = first.size(), len2 = second.size();
    if (abs(len1 - len2) > 1) return false;
    int i = 0, j = 0;
    int op_cnt = 0;
    while (i < len1 && j < len2) {
      if (first[i] == second[j]) {
        i++, j++;
      } else {
        if (first[i] == second[j+1]) {
          j++;
          if (op_cnt > 0) return false;
          else op_cnt++;
        } else if (first[i+1] == second[j]) {
          i++;
          if (op_cnt > 0) return false;
          else op_cnt++;
        } else {
          i++, j++;
          if (op_cnt > 0) return false;
          else op_cnt++;
        }
      }
    }
    if (max(len1 - i, len2 - j) + op_cnt > 1) return false;
    return true;
  }
};
```

