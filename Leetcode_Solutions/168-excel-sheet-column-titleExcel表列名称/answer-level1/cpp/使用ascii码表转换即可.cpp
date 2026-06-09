### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string convertToTitle(int n) {
        int mol = (n-1)%26;
        int div = (n-1)/26;
        char tmp = 'a' + mol - 32;
        string res(1, tmp);
        if(div == 0){
            return res;
        }
        return convertToTitle(div) + res;
    }
};
```