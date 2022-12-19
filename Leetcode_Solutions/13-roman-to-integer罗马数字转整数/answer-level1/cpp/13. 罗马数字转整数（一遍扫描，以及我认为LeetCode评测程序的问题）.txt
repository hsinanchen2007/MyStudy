# 罗马数字两条基本规则
1. 基本数字 I、X、C 中的任何一个自身连用构成数目，或者放在大数的右边连用构成数目，__都不能超过三个__；__放在大数的左边只能用一个__；
2. __不能__ 把基本数字 V、L、D 中的 __任何一个__ 作为小数 __放在大数的左边__ 采用相减的方法构成数目；放在 __大数的右边__ 采用相加的方式构成数目 __只能使用一个__。
# 思路
既然取值和后面一个字母的值有关，所以采用向后查看一个字符的分析方法（就叫L(1)分析法吧←其实这是仿照语法分析的时候“LL(1)”、“LR(1)”等分析法起的名2333）。
- 读取字母的时候除了M，其他都要向后查看一个字符，如果后面字母是`{I, X, C, M}`中的，并且比所读的这个字母代表的值大的话，那么所读的字母对应的值就取相反数。最后都加起来就行了。当然，也可以边读边加，事实证明这样更快。
# 代码  
执行用时 : 4 ms, 在Roman to Integer的C++提交中击败了100.00% 的用户  
内存消耗 : 8.2 MB, 在Roman to Integer的C++提交中击败了94.89% 的用户  
```cpp
int romanToInt(string s)
{
    int len = s.size();
    if (!len)
        return 0;
    int sum = 0;
    char next;
    for (int i = 0; i < len; i++)
    {
        if (i < len - 1)
            next = s[i + 1];
        else
            next = '\0';
        switch (s[i])
        {
        case 'M':
            sum += 1000;
            break;
        case 'D':
            if (next != 'M')
                sum += 500;
            else
                sum += -500;
            break;
        case 'C':
        {
            if (next != 'M' && next != 'D')
                sum += 100;
            else
                sum += -100;
            break;
        }
        case 'L':
            if (next != 'M' && next != 'D' && next != 'C')
                sum += 50;
            else
                sum += -50;
            break;
        case 'X':
        {
            if (next == 'X' || next == 'V' || next == 'I' || next == '\0')
                sum += 10;
            else
                sum += -10;
            break;
        }
        case 'V':
            if (next == 'V' || next == 'I' || next == '\0')
                sum += 5;
            else
                sum += -5;
            break;
        case 'I':
        {
            if (next == 'I' || next == '\0')
                sum += 1;
            else
                sum += -1;
            break;
        }
        }
    }
    return sum;
}
```
# LeetCode测试程序的问题
- 似乎LeetCode评测时的逻辑和那两条基本规则有些许不同——LeetCode的测试预期输出的逻辑是，只要后面的字母所代表的值比当前字母大，那么当前字母所代表的值就取相反数。但是其实按照罗马数字的规则V，L，D时不能出现在大数左侧的。因为不知道测试用例里会不会出现V，L，D出现在大数左侧的的用例，所以我就按照“只要后面的字母所代表的值比当前字母大，那么当前字母所代表的值就取相反数”的逻辑写的代码。