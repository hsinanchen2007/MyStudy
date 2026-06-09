### 解题思路
    二进制加法思路的延申。

### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
        //进位处理
        int carry=0;
        //从低位向高位计算，最后反转
        StringBuilder sb=new StringBuilder();
        for(int i=num1.length()-1,j=num2.length()-1;i>=0||j>=0;i--,j--)
        {
            //判断是否越界，不越界就取这个数
            int x=i>=0? num1.charAt(i)-'0':0;
            int y=j>=0? num2.charAt(j)-'0':0;
            //求和
            int sum=x+y+carry;
            //拼接
            sb.append(sum%10);
            //进位标志
            carry=sum/10; 
        }
        if(carry==1)  //最后还有一个仅为
            sb.append("1");  //不可能进位到2
        //反转
        return sb.reverse().toString();
    }
}
```