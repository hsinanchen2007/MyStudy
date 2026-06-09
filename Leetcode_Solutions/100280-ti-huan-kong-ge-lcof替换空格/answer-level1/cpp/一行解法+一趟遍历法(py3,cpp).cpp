### 思路一：一行 Python（不推荐）
使用 `replace` 函数即可。

#### 代码

```python []
class Solution:
    def replaceSpace(self, s: str) -> str:
        return s.replace(' ', '%20')
```
### 思路二：一趟遍历
初始化一个空的字符串 `res` 并遍历输入字符串的每个字符 `i`：
- 如果 `i` 不是空格，直接加到 `res` 上；
- 如果是空格，则将结果加 `%20`。

#### 代码
```python []
class Solution:
    def replaceSpace(self, s: str) -> str:
        res = ''
        for i in s:
            if i != ' ':
                res += i
            else:
                res += '%20'
        return res
```

```C++ []
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for(auto i:s){
            if(i != ' '){
                res += i;
            }else{
                res += "%20";
            }
        }
        return res;
    }
};
```

#### 复杂度分析
- 时间复杂度：$O(n)$，$n$ 为数组的长度，遍历了一遍数组。
- 空间复杂度：$O(n)$，使用了 `res`。