### 解题思路
题目的解释像个绕口令，其实很简单它的意思就是叫我们统计字符串中相邻不同字符之间各自有多少个字符的数目，举个例子就是222333这里就是3个2，3个3然后将其转换成字符串就是3233（3个2，3个3）。这里有点压缩数据的意思，例如我们的一串二进制字符串11110000000010，叫我们压缩一下表示成，41801110。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        String ret = "1";  //初始值
        for(int i = 1; i < n; i++) //总的循环次数
        {  
            StringBuffer newString = new StringBuffer();  //用于放置每次统计出来相同字符的容器
            int count = 0;  //计数器这里要从0开始
            char oldChar = ret.charAt(0); //旧字符
            for(int j = 0; j < ret.length(); j++)
            {
               if(oldChar == ret.charAt(j))  //判断旧的字符和新的字符是否相同若相同计数器加1
               {
                   count++;
               }
               else{
                   newString.append(count);  //若发现不同的字符以后我们将计数器+该字符存入容器中
                   newString.append(oldChar);
                   oldChar = ret.charAt(j);  //将新的字符代替旧字符
                   count = 1;  //这里计数器从1开始是因为我们这里新的字符存在了就要算一个
               }
            }
            newString.append(count);  //这里我们是为了在扫描完字符串之后将最后一个字符添加到容器中
            newString.append(oldChar);
            ret = newString.toString();
        }  
        return ret;
    }
}
```