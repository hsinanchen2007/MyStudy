### 解题思路
1. 因为操作只有一次，所以长度差不能大于1
2. 为了简化问题，把短的放在前边，这样只需要考虑增和改的问题
3. 只有一个差异点，所以可以先循环找到差异点。两种情况：已经到了最后，那就说明没问题（差一个字符或者不差）；如果在中间断了，判断后边的子字符串长度是否相等（修改，或者新增可以相等）

### 代码

```cpp
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (abs((int)first.size() - (int)second.size()) > 1) {
            return false;
        }

        if (second.length() < first.length()) {
            return oneEditAway(second, first);
        }

        int i=0;        
        while (i<first.length() && first[i] == second[i]) {
            i++;            
        }

        if (i == first.length()) {
            return true;
        }

        if (first.substr(i, first.length() - i) == second.substr(i+1, second.length() -i -1)) {
            return true;
        }

        if (first.substr(i+1, first.length() - i) == second.substr(i+1, second.length() -i -1)) {
            return true;
        }

        return false;
    }
};
```