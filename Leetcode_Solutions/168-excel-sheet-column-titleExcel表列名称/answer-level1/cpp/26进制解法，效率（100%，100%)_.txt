1 相当于是26进制进行计算。
2 26进制进行计算，需要进行起始位置对齐，具体方式为m = n - 1, 然后使用m进行%和/操作；
![image.png](https://pic.leetcode-cn.com/2366dbc4644b1e0895acaa8fd71378aee65e9a7646d992acbda7f9906ae4aace-image.png)

```
#define BASE_ALPAH 26
class Solution {
public:
    string convertToTitle(int n) {
        if(0 == n) return "";
        //26进制，1开始，注意起始位置的对齐。(n - 1) %26  + 'A'
        //通过/进行移位
        string str;
        do {
            char tmp = (n - 1) % BASE_ALPAH + 'A';
            str.insert(0,1,tmp);
            n = (n - 1) / BASE_ALPAH ;
        }
        while( n > 0);
        return str;

    }
};
```
![image.png](https://pic.leetcode-cn.com/fe315ba5683a500a8100b1cdee9c9eb5e53b6cc3f8884efdc9d968044cacbe63-image.png)

