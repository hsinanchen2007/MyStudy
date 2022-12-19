```
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> char_set;
        int result=0;
        for(char c:s){
            if(char_set.count(c)){
                result+=2;
                char_set.erase(c);
            }
            else{
                char_set.insert(c);
            }
        }
        if(!char_set.empty()) result++;
        return result;
    }
};
```

遍历一次字符串，如果该字符在set中不存在，向set中添加该字符。否则，则证明存在两个相同的字符可以凑成一对，result+=2，并删除set中该字符。最后如果set非空，则说明有落单的，可放在字符中间，result++。

代码逻辑挺简单的，但是执行时间不理想，可能是set的insert和erase操作相对其它的，比如数组直接访问的算法耗时大吧。
