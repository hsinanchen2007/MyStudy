### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int translateNum(int num) {
        if(num < 10) return 1;
        //abcdef
        int ef = num % 100;
        if(ef < 10 || ef > 25)
        return translateNum(num / 10);
        else
        return translateNum(num / 10) + translateNum(num / 100);

    } 
};
```