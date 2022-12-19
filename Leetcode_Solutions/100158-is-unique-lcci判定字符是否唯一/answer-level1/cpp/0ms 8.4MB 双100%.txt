### 解题思路

用位运算来进行判断
任何一个字母-'a'的ascii不会重复 
只需要将字母减去'a'的ascii拿来位移1
只要字母不重复 & 运算就会是0

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int record = 0;
        int move;
        for(auto i : astr)
        {
            move = i - 'a';
            if((record & (1 << move)) != 0)
                return false;
            else
            {
                record = record | (1 << move);
            }
        }
        return true;
    }
};
```