思路：
先找普通的例子，例如hello world，遇到空格把结果清零，计算最后一个单词的长度就好了；
特殊情况：结尾有n个空格；
只要一开始把结尾的空格处理掉即可，复杂度也不高；

```
class Solution {
public:
    int lengthOfLastWord(string s) {
        int result = 0;
        int index = s.size();
        for(int i = s.size() - 1; i > 0; i--) {
            if(s[i] == ' ')
                index = i;
            else
                break;
        }
        for (int i = 0; i < index; i++) {
            if(s[i] == ' ') {
                result = 0;
            }
            else {
                result++;
            }
        }
        return result;
    }
};
```
执行用时 :4 ms, 在所有 cpp 提交中击败了82.06%的用户
内存消耗 :8.7 MB, 在所有 cpp 提交中击败了87.02%的用户