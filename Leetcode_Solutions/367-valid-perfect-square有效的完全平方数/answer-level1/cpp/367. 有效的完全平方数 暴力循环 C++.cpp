### 解题思路
暴力循环 n的开平方其实是比较快的

### 代码

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {

        unsigned long long  i = 1;
        unsigned long long tmpnum = num;
        while(i*i<tmpnum){
            i++;
        }

        if(i*i == tmpnum){
            return true;
        }

        return false;

    }
};
```