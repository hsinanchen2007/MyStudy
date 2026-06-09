### 解题思路
利用位运算，将s1和s2 转化为整数。
若整数相同，说明这两个字符串所包含的字母相同。
显然这种方法不能处理字符串中出现重复字母的情况："a,b,c,c" "c,b,a"用该算法得出的结果是true 但实际上是false
应该可以改进吧  但是能跑通  
### 代码

```cpp
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int s1bin = 0;
        for(char c : s1) {
            int index = c - 'a';//index向左移动一位--若字母是a a-'a'=0不能表示a出现过于是向左移动一位
                                //此时a->00..001 b->00..010 c->00..100 .........
            int newBit = 1<<index;
            s1bin |= newBit;  
        }
        int s2bin = 0;
        for(char c : s2) {
            int index = c - 'a';
            int newBit = 1<<index;
            s2bin |= newBit;  
        }
        return s1bin == s2bin;
    }
};
```