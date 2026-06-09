题目说了很多，概括起来能够构成有效整数就以下三种情况:

```
1.第一个非空字母是 正/负 号，后面跟一连串数字
2.第一个非空字母是 数字，后面跟一连串数字
3.在满足以上两条之一的情况下，一连串数字后面如果存在其他字符，把其他字符删除，也就是说遍历到这里就可以暂停了
```
基于以上的情况：
```
使用一个字符类型的变量first来代表第一个非空字符
使用一个整形变量来代表最终的符号位，1表示正，-1表示负，默认为正。以兼容上面说的第二条
使用一个整形数组，将有效的连续字符串转成阿拉伯数字存储起来
```

下面是完整的代码(注释掉的内容是为了调试的方便)：
```
int myAtoi(string str) {
        int len=str.size();
        if(len==0)
            return 0;
        char first=' ';     //第一个非空字母
        int flag=1;         //1代表正数，-1代表负数
        vector<int> vec;   //存储有效数字的字符串
        for(int i=0;i<len;i++)
        {
            if(str[i]==' ' && first==' ')
                continue;
            if(str[i]!=' ' && first==' ')
            {
                if(str[i]=='+')
                    first='+';
                else if(str[i]=='-')
                {
                    first='-';
                    flag=-1;
                }
                else if(str[i]>='0' && str[i]<='9')
                {
                    first=str[i];
                    vec.push_back(str[i]-'0');
                }
                else//第一非空字母既不是数字也不是正负号
                    return 0;
                //cout<<str[i]<<"$";  
                continue;
            }
            //cout<<str[i]<<"^";
            //到这里，说明first不为空，判断有效数字，遇到非'0'-'9'的字符就退出
            if(str[i]>='0' && str[i]<='9')
                vec.push_back(str[i]-'0');
            else
                break;
        }
        if(first==' ')
            return 0;   //说明原字符串都是空字符
        if(first!=' ' && vec.size()==0)
            return 0;   //说明只有符号位
        long num=0;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]==0)
                continue;
            else
            {
                if((vec.size()-1-i)>11 && flag==1)
                    return  INT_MAX;
                else if((vec.size()-1-i)>11 && flag==-1)
                    return INT_MIN;
                num+=vec[i]*pow(10,vec.size()-1-i);
            }
        }
        num*=flag;
        if(num<INT_MIN)
            return INT_MIN;
        else if(num>INT_MAX)
            return INT_MAX;
        else
            return num;
    }
```
