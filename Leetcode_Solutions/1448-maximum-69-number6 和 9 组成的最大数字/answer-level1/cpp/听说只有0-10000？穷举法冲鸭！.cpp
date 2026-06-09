### 解题思路
穷举法写出第一个6在千位、百位、十位、个位

### 代码

```cpp
class Solution {
public:
    int maximum69Number (int num) {
        if(num/1000==6) num+=3000;
        else if(num/100==96||num/100==6) num+=300;
        else if(num/10==996||num/10==96||num/10==6) num+=30;
        else if(num%10==6) num+=3;
    else num=num;
    return num;

    }
};
```