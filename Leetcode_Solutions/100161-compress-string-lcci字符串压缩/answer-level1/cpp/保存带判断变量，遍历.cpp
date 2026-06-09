```
string compressString(string S)
{
    string ans="";

    char sentry=S[0];//保存带判断字符
    int num=0;//字符出现次数
    for(int i=0;i<S.length();i++)
    {
        if(sentry==S[i])
        {
            num++;
        }
        else
        {
            ans+=sentry;
            ans+=to_string(num);
            sentry=S[i];//更新待判断字符
            num=0;//更新次数
            num++;//当前字符已经出现过一次，加1
        }
    }
    ans+=S[S.length()-1];//处理最后一个字符
    ans+=to_string(num);

    if(ans.length()<S.length())
        return ans;
    else
        return S;
}
```
