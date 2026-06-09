维护左括号数，如果左括号数 = 0，右括号数 > 0,则无效的括号必须+1。若左括号数>0,则每出现一个左括号，左括号数+1， 每出现一个右括号，左括号数减1.最终加上剩余的左括号数，即为最终的结果。

```
class Solution {
public:
    int minAddToMakeValid(string S) {
        int left = 0;

        int invalid = 0;

        for(int i = 0; i < S.length(); i++)
        {
            if(S[i] == '(')
            {
                left ++;
            }
            else {
                if (left > 0)
                {
                    left --;
                }
                else {
                    invalid ++;
                }
            }
        }
        return (invalid + left);
    }
};
```
