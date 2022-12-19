# 数学益智类 题目。
# 适合用于熟悉新学习的编程语言练习。
**解析**
回文字符串可从对称中心被分为左右两个部分。则其左侧出现的同类字符的个数应当等于右侧出现的同类字符的个数。（例如左侧M个a则右侧也要出现M个a）
其次，当 最长回文字符串长度<原字符串s 时，最长回文串必定为奇数个。（例如s="aabbcd"时，最长串应为左右两侧分布a,b对称中心为一个单独的字符）

我们应该完成的任务：
1.统计出现s中相同类型字符的个数。
2.判断有多少个字符可被用于构造回文字符串。（当某种字符出现奇数次时，需减去多余的一个）
3.判断s的长度与我们分析出的result结果是否相等，并返回长度。

1.
    for (i=0;i < strlen(s);i++)
    {
        num_s[s[i]]++;
    }
2.
    for (i=0;i < 123;i++)
    {
        result=result+num_s[i]-num_s[i]%2;
    }
3.
    if (result == strlen(s)) return result;
    else return result+1;

完整代码
int longestPalindrome(char * s){

    int num_s[123]={0};//ASCII码中，小写字母z对应122
    int i=0,result=0;

    for (i=0;i < strlen(s);i++)
    {
        num_s[s[i]]++;
    }

    for (i=0;i < 123;i++)
    {
        result=result+num_s[i]-num_s[i]%2;
    }

    if (result == strlen(s)) return result;
    else return result+1;
}