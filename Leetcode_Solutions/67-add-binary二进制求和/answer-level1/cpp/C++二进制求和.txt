二进制求和最简洁还是用位运算，不过这题是用字符串，而字符串转成数字非常容易溢出，还是老实用遍历吧。
题解由两部分组成，字符串对齐和相加
我认为翻转比较死板...还是直接头部插入更加方便。

1.字符串对齐
```
while(a.size()<b.size())
    a.insert(a.begin(),'0');
while(a.size()>b.size())
    b.insert(b.begin(),'0');
```

2.遍历+头部插入
头部插入有两种方法
    
1.调用函数
    
    ```
     a.insert(a.begin(),'0')//注意是字符'' 
    ```
    
    
2.使用字符串操作符+=
```
a='0'+a;
```

    
    
在Java中可以提前创建一个StringBuilder类来加快字符串操作符的重载

进位可以选择if-else或者switch

if-else
```
for(int k=i;k>=0;k--)
        {
            if(a[k]-'0'+b[k]-'0'+flag==0)
            {
                a[k]='0';
                flag=0;
            }
            else if(a[k]-'0'+b[k]-'0'+flag==1)
            {
                a[k]='1';
                flag=0;
            }
            else if(a[k]-'0'+b[k]-'0'+flag==2)
            {
                a[k]='0';
                flag=1;
            }
            else if(a[k]-'0'+b[k]-'0'+flag==3)
            {
                a[k]='1';
                flag=1;
            }
        }
        if(flag==1)
            a='1'+a;
        return a;
```
switch
```
for(int k=i;k>=0;k--)
        {
            int num=a[k]-'0'+b[k]-'0'+flag;
            switch(num)
            {
                case 0:
                    {
                        a[k]='0';
                        flag=0;
                        break;
                    }
                case 1:
                    {
                        a[k]='1';
                        flag=0;
                        break;
                    }
                case 2:
                    {
                        a[k]='0';
                        flag=1;
                        break;
                    }
                case 3:
                    {
                        a[k]='1';
                        flag=1;
                        break;
                    }
            }
        }
        if(flag==1)
            a='1'+a;
        return a;
```
直接对在原有字符串的基础上进行操作，可以省去建立res字符串的空间。
时间复杂度应该是O(n)
内存占用8.7，比较高。欢迎各位讨论


