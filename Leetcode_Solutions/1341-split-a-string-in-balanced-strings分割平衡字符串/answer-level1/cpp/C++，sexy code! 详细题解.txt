## 思路
- 跟栈的实现方法类似
- 要求尽可能多的对称，遍历字符串，以L开头为例，计录遇到L的数量，当遇到L时，L的数量加一，当遇到R时，此时的R能匹配走一个L，L的数量减一
- 当L的数量为空时，获得一个最小的平衡字符串。
```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, l = 0, r = 0;
        for(char i : s){ // 遍历
            if(l == 0 && r == 0) i == 'L' ? ++ l: ++ r;
            else if(l > 0)  i == 'L' ? ++ l : -- l;
            else if(r > 0)  i == 'R' ? ++ r: -- r;
            if(l == 0 && r == 0)    ++ ans;
        }
        return ans;
    }
};
```
根据评论区 菜哥 的建议改进代码
```cpp
class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, flag = 0;
        for(char i : s){ // 遍历
            i == 'L'? ++ flag: -- flag;
            if(flag == 0)   ++ ans;
        }
        return ans;
    }
};
```

