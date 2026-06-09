#  Excel表列序号
给定一个Excel表格中的列名称，返回其相应的列序号。

例如，

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
示例 1:

```
输入: "A"
输出: 1
```
示例 2:

```
输入: "AB"
输出: 28
```

示例 3:

```
输入: "ZY"
输出: 701
```

<hr>

##  解：
该题目的意思其实就是26进制转十进制，其中1\~26分别用A\~Z表示，其实就是个进制转化问题

```
class Solution {
public:
    int titleToNumber(string s) {
        int sum=0;//结果
        int n=s.size()-1;//阶数
        for(int i=0;i<s.size();i++)
        {
            int temp=pow(26,n)*(s[i]-'A'+1);
            sum+=temp;
            n--;
        }
        return sum;
    }
};
```

