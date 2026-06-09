### 解题思路
利用数电全加器的思想
全加器输入输出特性为
![image.png](https://pic.leetcode-cn.com/aae44e82176b0d018f317210f277c05aa216252f68cac04f9271f5ee11c069e2-image.png)
先添加先导0保证两字符串等长
然后按位相加

### 代码

```cpp
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()){
            string t = a;
            a = b;
            b = t;
        }//确保a不比b长
        for(int i = a.size();i<b.size();i++){
            a  = '0' + a; //补上先导零
        }
        bool c = 0;
        string res = "";
        for(int i = b.size() - 1; i >= 0; i--){
            bool ax = (a[i] - '0');
            bool bx = (b[i] - '0');
            bool s = ax ^ bx ^ c;
            c = ax & bx | c&(ax | bx);
            res = (char)(s + '0') + res;
        }
        if(c == 1)
            res = '1' + res;
        return res;
    }
};
```