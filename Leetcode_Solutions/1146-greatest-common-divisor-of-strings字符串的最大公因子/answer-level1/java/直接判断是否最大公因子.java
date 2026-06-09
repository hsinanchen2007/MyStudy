### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
String s="";
if(str1.length() > str2.length())
{
String ss = str1;
str1 = str2;
str2 = ss;
}
  String temp1 = str1 + str2;
    String temp2 = str2 + str1;
     if(!temp1.equals(temp2))
{
return s;
}
for(int i = str1.length();i > 0;i--)
{
String temp = str1.substring(0,i);
int l = temp.length();
if(str2.length() % l ==0 && str1.length() % l ==0)
{
    return temp;
}
}

return s;
    }
}
```