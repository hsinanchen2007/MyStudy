看到很多大佬使用哈希表，刚开始想不到，就想到了最简单的if else写了一个函数模板，接着提取出千百十个位上的数字传递到函数模板中，再按照顺序将所得到的结果相加。
```
class Solution {
public:
    string intToRoman(int num) 
    {
        string res;
        int qian = num / 1000;
        int bai = num % 1000 / 100;
        int shi = num % 100 / 10;
        int ge = num % 10;
        res += split(qian, "", "", "M");
        res += split(bai, "D", "M", "C");
        res += split(shi, "L", "C", "X");
        res += split(ge, "V", "X", "I");
        return res;
    }
private:
    string split(int n, string five, string ten, string one)
    {
        string res;
        if(n == 0)
            res="";
        else if(n < 4)
        {
            for(int i=1; i<=n; i++)
            {
                res += one;
            }
        }
        else if(n == 4)
            res = one+five;
        else if(n == 5)
        {
            res = five;
        }
        else if(n>5 && n<9)
        {
            res = five;
            for(int i=1; i<=n-5; i++)
                res = res + one;
        }
        else if(n == 9)
            res = one + ten;
        return res;
    }
};
```

输出结果如下：
```
Accepted
3999/3999 cases passed (12 ms)
Your runtime beats 70.45 % of cpp submissions
Your memory usage beats 50.32 % of cpp submissions (8.7 MB)
```