### 解题思路
循环，用stringbuilder进行拼接，最后用reverse，再用tostring进行字符串转换
当前位置为sum%2
进位为sum/2

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        int m=a.length();
        int n=b.length();
        StringBuilder sb=new StringBuilder();
        int prex=0;
        for (int i=m-1,j=n-1;i>=0||j>=0;i--,j--)
        {
            int sum=prex;
            sum+= i>=0?a.charAt(i)-'0' :0;
            sum+= j>=0?b.charAt(j)-'0' :0;
            sb.append(sum%2);
            prex=sum/2;

        }
        if (prex>0)
            sb.append(prex);
        return sb.reverse().toString();
    }
}
```