### 解题思路
栈：循环遍历，遍历元素与栈顶相等时弹出，剩余元素构成字符串

### 代码

```cpp
class Solution {
public:
    string removeDuplicates(string S)
    {
        deque<char> buff;

        for (auto c : S) {
            if (!buff.empty() && buff.front() == c) {
                buff.pop_front();
            } else {
                buff.push_front(c);
            }
        }

        string result = "";
        for (auto c : buff) {
            result.push_back(c);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
```