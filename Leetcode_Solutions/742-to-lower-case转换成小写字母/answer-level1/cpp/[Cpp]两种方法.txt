

常规策略

```cpp
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i <str.size(); i++){
            if ( str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] - 'A' + 'a';
            }
        }
        return str;

    }
};
```

位运算: 和32`0b'100'000`按位或, 能够让大写变小写，小写不变

原因是:A, 在ASCII对应65， 也就是`0b1'000'001`, 而a是97对应`0b1'100'001`. 和32按位或操作，让原来`0b1'000'001`的第6位变为1，就成了a的二进制表示

```cpp
class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i <str.size(); i++){
            str[i] |= 32;
        }
        return str;

    }
};
```

