### 解题思路

![image.png](https://pic.leetcode-cn.com/f2ba6e9359a8189c71762b3169fa522c3810ebd6ca1bf87261a0162adf7b7885-image.png)

### 代码

```cpp
class Solution {
public:
    int outofrang(int &num,int plus,int &negative)
    {
        if(negative>0)
        {
            if((num>=214748364&&plus>6)||num>214748365)return 2147483647;
            else return 0;
        }
        else
        {
            if((num>=214748364&&plus>7)||num>214748365)return -2147483648;
            else return 0;
        }
    }
    int myAtoi(string str) {
       int i=0;
       for(;i<str.size();i++)
       {
           if(str[i]!=' ')break;
       } 
       if(i==str.size())return 0;
       int negative=1;
       int num=0;
       if(isdigit(str[i])){num=str[i]-48;}
       else{
           switch(str[i])
        {
            case '+':break;
            case '-':negative=-1;break;
            default:return 0;
        }
       }
       i++;
       for(;i<str.size();i++)
       {
           if(isdigit(str[i]))
           {   if(outofrang(num,str[i]-48,negative)==0)
               num=num*10+(str[i]-48);
               else return outofrang(num,str[i]-48,negative);
               
            }
           else break;
       }
       return num*negative;
       

    }
};
```

这道题官方给了一个很不错的状态机解法，这里是小白硬上的题解。分而治之的确很管用，但是一定要小心。