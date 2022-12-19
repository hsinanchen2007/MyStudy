![双百](https://pic.leetcode-cn.com/de2e3ebf7ae813df49dccb15024fcf024239cd61ce99dcf8f2df401c7351fe8b)

这个题我是感觉挺无语的，没什么意思~~~


代码给出了，注释写的应该可以让别人看懂，有什什么问题欢迎指出~~~


**代码：**

```cpp
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        // cur1 是name的索引，cur2是typed的索引，prev1 = cur - 1 
        int prev1 = 0, cur1 = 0, cur2 = 0;
        while(cur1<name.size() && cur2<typed.size()){
            //  如果 name 和 typed 对应位置相同, 则同时往后移
            while(cur1<name.size() && cur2<typed.size() && name[cur1] == typed[cur2]){
                cur1 += 1; cur2 += 1;
            }
            // prev1 表示 name 和 typed 对应位置不相同, cur1的前一位
            prev1 = cur1 - 1;
            if(prev1 < 0) return false;
            // 此时处理长按情况: 因为长按时, typed[cur2] 应该是等于 name[prev1]的
            while(cur1<name.size() && cur2<typed.size() && name[prev1] == typed[cur2]){
                cur2 += 1;
            }
            // 处理完长按之后, 此时name 和 typed的对应位置应该是相等的
            if(cur1<name.size() && cur2<typed.size() && name[cur1] != typed[cur2]){
                return false;
            }
        }
        // 当name全部遍历完, 则认为 true
        return cur1 == name.size();
    }
};
```