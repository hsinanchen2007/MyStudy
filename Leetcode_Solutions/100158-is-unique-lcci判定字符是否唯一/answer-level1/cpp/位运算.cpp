### 解题思路
位运算，将一个int变量看成长度为32的数组，然后与操作根据某位进行判别

### 代码

```cpp
class Solution {
public:
    bool isUnique(string astr) {
        int str = 0;
        for(char c : astr){
            int index = c - 'a';
            int newBit = 1<<index;
            if((newBit & str) == newBit){
                return false;
            }
            str = str | newBit;
        }
        return true;
    }
};
```