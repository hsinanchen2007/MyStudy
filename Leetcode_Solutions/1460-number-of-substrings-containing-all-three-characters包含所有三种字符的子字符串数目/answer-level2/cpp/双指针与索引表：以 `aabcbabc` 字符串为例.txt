第 3 题可以依靠双指针与索引表实现。

## 大致过程

我们简单叙述稍复杂一些的字符串 `aabcbabc` 的结果。答案是 18。

首先，我们构建一个关于 abc 数量的索引表 `with_abc`。我们初始化左指针 `pl = 0`，以及右指针 `pr = 0`；遵循以下循环：

- 当前是情况是
  ```
  aabcbabc
  -
  ```
  当前的索引只有一个 `a`，而不是有 `a`, `b`, `c` 至少各一个。因此右移右指针，直到索引有 `a`, `b`, `c` 至少各一个。

- 现在的情况是 `pl = 0`, `pr = 3`
  ```
  aabcbabc
  ----
  ```
  这种情况下，我们发现能作为答案的包含 `abc` 的字符串会有 `aabc`, `aabcb`, `aabcba`, `aabcbab`, `aabcbabc` 五种。这五种恰好对应 `s.size() - pr = 8 - 3 = 5`。
  随后我们右移左指针。

- 现在的情况是 `pl = 1`, `pr = 3`，索引仍然包含了所有 `a`, `b`, `c` 至少各一个。
  ```
  aabcbabc
   ---
  ```
  同样地，这会产生五种可能的结果，对应 `s.size() - pr = 8 - 3 = 5`。
  我们再右移左指针。

- 现在的情况是 `pl = 2`, `pr = 3`，索引不包含 `a`：
  ```
  aabcbabc
    --
  ```
  我们需要右移右指针，使得索引包含 `a` (`pl = 2`, `pr = 5`)：
  ```
  aabcbabc
    ----
  ```
  这时可能的答案有 3 种。

如此往复，我们就可以得到结果了。剩下的情况有

- ```
  aabcbabc  // 3 种
     ---
  ```
- ```
  aabcbabc  // 1 种
      ----
  ```
- ```
  aabcbabc  // 1 种
       ---
  ```

总共 5 + 5 + 3 + 3 + 1 + 1 = 18 种情况。

## 复杂度

从下述代码，可以看出，每次 `while` 语句都右移一次指针，或者右指针或者左指针，并且 `while` 语句内是常数复杂度，因此总体复杂度是 $O(n)$。

但耗时有点长啊，大概 170 ms 左右 =.=

## 代码

```c++
class Solution {
public:
    int numberOfSubstrings(string s) {
        if (s.size() <= 2) return 0;
        // 索引表 `with_abc`：记录当前索引中字符的出现次数
        unordered_map<char, int> with_abc{ {'a', 0}, {'b', 0}, {'c', 0} };
        // 函数 `check_abc`：检查索引表是否包含了所有字符
        auto check_abc = [&with_abc]() { return (with_abc['a'] > 0) && (with_abc['b'] > 0) && (with_abc['c'] > 0); };
        // 左指针 pl，右指针 pr；指针用 int 型替代
        int pl = 0; int pr = pl;
        // result
        int result = 0;
        // 首先以字符串 `s` 的第一个字符初始化索引
        with_abc[s[pl]] += 1;

        while (pr < s.size()) {
            if (!check_abc()) {               // 若当前索引不包含所有字符
                ++pr; with_abc[s[pr]] += 1;   // 那么右指针 +1 并更新索引
                if (pr >= s.size()) break;    // 若右指针超出字符串，结束循环
            }
            else { with_abc[s[pl]] -= 1; ++pl; }       // 若当前索引包含所有字符，那么左指针 +1 并更新索引
            if (check_abc()) result += s.size() - pr;  // 若指针移动后的索引包含所有字符，那么更新结果
        }
        return result;
    }
};
```