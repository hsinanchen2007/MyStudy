### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int myAtoi(String str) {
  char[] chars = str.toCharArray();
        int n = chars.length;
        int idx = 0;
        while (idx < n && chars[idx] == ' ') {
            // 去掉前导空格
            idx++;
        }
        int flag =1;
if(idx==n)
{
return 0;
}
if(chars[idx] == '+')
{
flag =1;
idx++;
}
else if(chars[idx] == '-')
{
flag = -1;
idx++;
}
else if(chars[idx] <'0' && chars[idx] >'9')
{
return 0;
}
int ans =0; int dig = 0;
for(int i= idx;i<str.length();i++)
{
if(!Character.isDigit(chars[i]))
{
break;
}
 int digit = chars[i] - '0';
 
   if (ans > (Integer.MAX_VALUE-digit)/10) {
                return flag==1?  Integer.MAX_VALUE:Integer.MIN_VALUE;
            }
             ans = ans * 10 + digit;
}
return flag == 1? ans : -ans;
    }
}
```