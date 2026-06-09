这道题前部分思路比较清晰，这里主要想说说溢出判断。
笔者编程新手，卡在了溢出判断这，看了大神的解答后一脸懵逼。
什么INT_MIN、INT_MAX还要记个位数的7和8，属实头秃...
然后就想能不能用最小白的方式解决这个问题呢？
突然发现，我传到stringstream的数据在转出成int格式时被改了！
转换前：9646324351 ； 转换后：2147483647。
凭什么改我的数据！
所以我就想，是不是比较转换前后两个字符串是否相同就好了呢？
第一位可能是符号位，不好比较；2、3位又可能是0，还是不好比较。
所以，最简单的溢出判断方法就产生了：
**比较转换前后字符串的末尾是否相等！**
**若不相等，一定是内存溢出！**

附上代码：
```
class Solution {
public:
    int reverse(int x) 
    {
        if(x >= 0 && x < 10){return x;}
        int result;
        char ch[100] = {'\0'};
        sprintf(ch , "%d" , x);
        string s = ch;
        int p = s.find_first_not_of("-");
        std::reverse(s.begin()+p , s.end());
        stringstream ss;
        ss << s;    //转换前的结果
        ss >> result;
        sprintf(ch , "%d" , result);
        string sss = ch;    //转换后的结果
        if(sss[sss.size()-1] != s[s.size()-1])  //就是这里！！！
        {
            return 0;
        }
        return result;
    }
};
```
