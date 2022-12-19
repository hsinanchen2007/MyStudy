##### 三个步骤完成题目要求
输入样例如下
```
"  the sky  is     blue  "
```
### 步骤一，翻转整个字符串
```
"  eulb     si  yks eht  "
```
### 步骤二，翻转每一个单词
```
"  blue     is  sky the  "
```
### 步骤三，删除多余空格
```
"blue is sky the"
```
代码实现如下：
```
string reverseWords(string s)
{
    for (int i = 0; i < s.size() / 2; i++) // 第一步，翻转整个字符串
        swap(s[i], s[s.size() - i - 1]);
    int f = -1, b = -1; // 第二步，翻转每一个单词
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ' && f == -1) // f记录单词开始位置
            f = i;
        else if ((s[i] == ' ' || i == s.size() - 1) && f != -1)
        {
            b = i - (i != s.size() - 1); //b记录单词结束位置（两个判断条件：当前为空格 或 当前为字符串末尾）
            while (f < b)
                swap(s[f++], s[b--]);
            f = -1;
            b = -1;
        }
    }
    int p = 0; // 第三步，删除多余空格
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            if (i > 0 && s[i - 1] == ' ' && p != 0)// 如果不是开头且且下一位为非空格字符，保留一个空格
                s[p++] = ' ';
            s[p++] = s[i];
        }
    }
    s.erase(s.begin() + p, s.end());
    return s;
}
```


