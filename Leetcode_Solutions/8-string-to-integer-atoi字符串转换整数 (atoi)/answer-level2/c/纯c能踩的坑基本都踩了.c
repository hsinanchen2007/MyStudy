在二十次提交之后终于过了，踩在了各种内存不足，以及神奇的输入的坑上
```
int myAtoi(char* str)
{
    int len = strlen(str);
    int ret = 0;
    int flag = 1;
    int change = 0;
    int getnumber = 0;
    const int INF_MAX = 2147483647;
    const int INF_MIN = -2147483648;
    for (int i = 0; i <= len; i++)
    {
        if (str[i] == 32 && getnumber == 0 && change == 0)
            //略去空格
            continue;
        else if (str[i] == 32 && (getnumber != 0 || change !=0))
            //存在空格跳出
            return flag*ret;
        else if (str[i] == 45 && ret == 0 && change == 0 && getnumber == 0)
            //标记负号
        {
            flag = -1;
            change = 1;
        }
        else if (str[i] == 43 && ret == 0 && change == 0 && getnumber == 0)
            //标记正号
        {
            flag = 1;
            change = 1;
        }
        else if (str[i] < 48 || str[i]>57)
            //非数字元素退出
            break;
        else if (str[i] >= 48 && str[i] <= 57)
            //数字元素
        {
            if (flag ==1 )
            {
                 if(ret > 214748364 || (ret == 214748364 && str[i] >= 55))
                    return INF_MAX;
            }
            else if (flag ==-1 )
            {
                 if(ret > 214748364 || (ret == 214748364 && str[i] >= 56))
                    return INF_MIN;
            }
            getnumber += 1;
            ret = ret * 10;
            ret += (str[i] - 48);
        }
    }
    return flag * ret;
}
```
