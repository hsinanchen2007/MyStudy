### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String compressString(String S) {
int len = S.length();
if(len <= 2)
{
return S;
}
String result = "";
int count = 1;
for(int i=0;i<len-1;i++)
{
   
if(S.charAt(i) == S.charAt(i+1))
{
count++;
}
else
{
result += S.charAt(i);
result += count;
count =1;
} 
}


if(count != 1)
{
result += S.charAt(len-1);
result += count;
}
else
{
result += S.charAt(len-1);
result += 1;
}
if(len > result.length())
{
return result;
}
return S;
    }
}
```