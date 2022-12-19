### 解题思路
表面两次循环，其实只有一次遍历
第一趟循环找出字符串从哪位开始是有效的
第二趟计算值

### 代码

```cpp
class Solution {
public:
    int myAtoi(string str) {
        int start=0;//第二次循环开始位置
        int minus=1;//+ -标记
        long result=0;//结果
     for(int i=0;i<str.length();++i)
     {
         if(str[i]==' ')continue;//空格跳过本次循环
         else if(str[i]>='0'&&str[i]<='9')//记录第二次循环开始位置
         {
             start=i;
             break;

         }
         else if(str[i]=='+')
         {    ++i;
             start=i;
            break;

         }
         else if(str[i]=='-')//将minus记为-1
         {  ++i;
             minus=-1;
             start=i;
             break;

         }
        else return 0;



     }
     for(int i=start;i<str.length();++i) //第二次循环开始
     {
         if(str[i]>='0'&&str[i]<='9')
         {
             result=result*10+str[i]-48;//整数0-9等于其ASCII码-48
             if(result>INT_MAX)
             {
                 if(minus==1) return INT_MAX;
                 else return INT_MIN;


             }
         }
            else break;

         }

        result=result*minus;
        return result;

     
    }
};
```