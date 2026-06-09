```
bool isPalindrome(char * s)
{
    if(s == NULL)return false;
    if(strlen(s) == 0)return true;
    int len = strlen(s);

    for(int i=0,j=len-1;i<j;)
    {
        //头指针寻找字符或者数字，且大写转小写
        if((s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
        {

        }
        else if(s[i]>='A'&&s[i]<='Z')
        {
            s[i] = s[i] + 'a'-'A';
        }
        else
        {
            i++;continue;
        }
        //尾指针寻找字符或者数字，且大写转小写
        if((s[j]>='a'&&s[j]<='z')||(s[j]>='0'&&s[j]<='9'))
        {

        }
        else if(s[j]>='A'&&s[j]<='Z')
        {
            s[j] = s[j] + 'a'-'A';
        }
        else
        {
            j--;continue;
        }

        if(s[i]==s[j])
        {
            i++;j--;
        }
        else
        {
            return false;
        }
    }
     return true;
}
```
