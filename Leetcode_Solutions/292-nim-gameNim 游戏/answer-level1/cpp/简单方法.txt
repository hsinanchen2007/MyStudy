### 解题思路
此处撰写解题思路
能被4整除的都不行，反之都可以；
因为你是个聪明人。
### 代码

```cpp
class Solution {
public:
    bool canWinNim(int n) {
        if(n%4==0){
            return false;
        }
        return true;
    }
};
```