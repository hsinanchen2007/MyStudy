### 解题思路
1.去掉首尾空格;
2.首个非空的字符必须为-，+，数字;
    2.1如果当前字符是符号：
        2.1.1如果当前已经不是第一个字符：判断符号的前一个什么都不能有，也就是说不能出现数字，符号;
        2.1.2如果当前是第一个字符，看看是正还是负，修改c的值，c=1为正，0为负;
    2.2如果当前字符是数字：
        2.2.1将当前字符化成int型，然后看看是否超过取值范围
（q*10-digit<-2147483648）,由于左边这个式子测试的时候会提示，超出范围，所以写成q<(-2147483648+digit)/10，如果超出范围，返回相应的值;
    2.3如果是其他类型的字符，直接结束循环，break;
3.当一切顺利进行完，仍进行到现在时，需要将result赋予正负号。最后再返回一个0就行。

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        //去掉开头和尾部的空格
        str=str.trim();
        //这个用来存放char数组
        char[] array=new char[str.length()];
        //最终结果
        int result=0;
        //用来判断是正的还是负的
        int c=1;
        //将str分成char数组并存入array中
        for(int i=0;i<str.length();i++)
        {
            array[i]=str.charAt(i);
        }
        //一个一个开始看
        for(int i=0;i<str.length();i++)
        {
            char a=array[i];
            //首个非空的字符必须为-，+，数字
            if((array[0]=='-'||array[0]=='+'||Character.isDigit(array[0])))
            {
                //如果当前为符号
                if(a=='-'||a=='+')
                {
                    //看是否是第一个
                    if(i>0)
                    {
                        //不是第一个，就看看他的前面是不是数字
                        if('0'<=array[i-1]&&array[i-1]<='9')
                        {
                            //是数字，返回0
                            break;
                        }
                        if(array[i-1]=='-'||array[i-1]=='+')
                        {
                            //是符号，返回0
                            return 0;
                        }
                    }
                    //如果第一个非空字符为正或者负号时
                    else if(a=='-')
                    {
                        c=-1;
                    }
                    else if(a=='+'){
                        c=1;
                    }
                }
                //当前字符是数字
                else if(Character.isDigit(a))
                {
                    int digit=a-'0';
                    if(c==-1)
                    {
                        int q=0-result;
                        if(q<(-2147483648+digit)/10)
                        {
                            return -2147483648;
                        }
                            
                    }
                    if(c==1)
                    {
                        int q=result;
                        if(q>(2147483647-digit)/10)
                        {
                            return 2147483647;
                        }
                            
                    }
                    result=result*10+digit;
                }
                else{
                    break;
                }
            }
            //否则，返回0，即无法进行转换
            else{
                return 0;
            }
    }
        if(c==-1)
        {
            result=0-result;
        }
        if(-2147483648<=result&&result<=2147483647)
        {
            return result;
        }
        return 0;
    }
}
```