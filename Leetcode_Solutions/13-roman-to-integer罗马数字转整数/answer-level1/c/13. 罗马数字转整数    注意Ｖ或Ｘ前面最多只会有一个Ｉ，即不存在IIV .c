### 解题思路
注意Ｖ　或者　Ｘ　前面最多只会有一个Ｉ，　　即不存在IIV  


罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

示例 1:

输入: "III"
输出: 3



### 代码

```c
int romanToInt(char * s){
    int sum = 0;

    while(*s != '\0') {
        switch (*s) {
            case 'I':
                sum = (*(s+1) == 'V' || *(s+1) == 'X') ? (sum - 1) : (sum + 1);
                break;
            case 'V':
                sum = sum + 5;
                break;
            case 'X':
                sum = (*(s+1) == 'L' || *(s+1) == 'C') ? (sum - 10) : (sum + 10);
                break;
            case 'L':
                sum = sum + 50;
                break;
            case 'C':
                sum = (*(s+1) == 'D' || *(s+1) == 'M') ? (sum - 100) : (sum + 100);
                break;
            case 'D':
                sum = sum + 500;
                break;
            case 'M':
                sum = sum + 1000;
                break;
        }
        s++;
    }
    
    return sum;
}
```