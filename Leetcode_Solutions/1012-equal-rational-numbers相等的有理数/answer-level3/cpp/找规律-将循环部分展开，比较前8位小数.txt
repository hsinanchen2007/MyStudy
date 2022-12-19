### 解题思路
这题只要找到规律，就是 Medium 或 Easy 级别的题。
由于题目说明：非循环部分和循环部分都 $<= 4$ 位，故只需比较 $S$ 和 $T$ 的整数和前 $8$ 位小数即可。
举个例子：$S = 1.1234(1234)$，$T = 1.123(4123)$。
将 $S$ 和 $T$ 的小数部分展开成小数点后 8 位：
- $S = 1.12341234$
- $T = 1.12341234$

$S$ 和 $T$ 的循环部分的周期为 $4$，$S$ 循环部分从第 $5$ 位开始，$T$ 的循环部分从第 $4$ 位开始。
- 当 $n > 8$ 时，$S$ 的第 $n$ 位小数 $==$ $S$ 的第 $n - 4$ 位小数；
- 当 $n > 7$ 时，$T$ 的第 $n$ 位小数 $==$ $T$ 的第 $n - 4$ 位小数。

因此只需要比较 $S$ 和 $T$ 的前 $8$ 位小数，如果相等，则其余的循环部分一定相等。
另外再注意 $0.999....$ 进位即可。

（另一个思路是将 $S$ 和 $T$ 都转化成浮点数，然后只要差值很小即可，更 easy 了）

### 代码

```cpp
class Solution {
public:
    bool isRationalEqual(string S, string T) {
        return conv(S) == conv(T);
    }
    string conv(string& s) {
        // 去除前导零
        if(s[0] == '0' && s[1] >= '0' && s[1] <= '9')
            s.erase(s.begin());
        
        // 找到小数点、左括号、右括号
        size_t point = s.find("."), left = s.find("("), right = s.find(")");
        if(point == string::npos) { // 如果没有小数点就添加一个
            s += '.';
            point = s.size() - 1;
        }

        // 将循环小数展开成小数点后 8 位小数
        string rep = "0";
        if(left != string::npos) {
            rep = s.substr(left + 1, right - left - 1);
            s = s.substr(0, left);
        }
        while(s.size() - point - 1 < 8)
            s += rep;
        s = s.substr(0,9 + point);

        // 如果循环部分是 99.. 则进位
        for(int i = 0; i < rep.size(); ++i)
            if(rep[i] != '9')
                return s;
        int p = s.size() - 1;
        for(; s[p] == '9' || s[p] == '.'; --p) {
            if(s[p] != '.')
                s[p] = '0';
            if(p == 0)
                return '1' + s;
        }
        s[p] += 1;
        return s;
    }  
};
```