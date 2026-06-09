### 解题思路
刚入门怎么都想不同递归过程，画颗递归树就很好理解了。
递归的过程就是从上往下，到底之后处理结果，然后回溯~


### 代码

```cpp
class Solution {
        vector<string> res;
public:
    vector<string> generateParenthesis(int n) {
        string s;
        backTrace(s, n, n);
        return res;

    }
    void backTrace(string s, int left_cnt, int right_cnt) {
        //左括号剩的比右括号多，一定是错的，也就是说，必须是左括号先用完
        if (left_cnt > right_cnt)  return;
        //左右括号都合理的被用完了，就得到了正确结果
        if (left_cnt == 0 && right_cnt == 0) {
            res.push_back(s);
            return;
        }
        //左括号有剩余，就加左括号
        if (left_cnt > 0) {
            backTrace(s+'(', left_cnt - 1,right_cnt);
        }
        //右括号有剩余，就加右括号
        if (right_cnt > 0) {
            backTrace(s+')', left_cnt, right_cnt - 1);
        }
        
    }
};
```