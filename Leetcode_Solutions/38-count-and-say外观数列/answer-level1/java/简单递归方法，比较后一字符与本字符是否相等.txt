### 解题思路
递归方法，每次都先得到上一个的字符串；
比较字符串下一个字符和本字符是否相等，若相等，则计数加一，若不等，就把之前计数的值和本字符添加进字符串；
思路很简单，主要是理清最后一个字符串怎么比较，因为有i+1的存在
①若最后一个和倒数第二个不相等，在上一个循环里把倒数第二个的情况就加进去了这次循环就只需要加“1”个“最后的数”
②若最后一个数和倒数第二个相等，最后一个数的次数也已经加上去了，也就只用加“count”个“最后的数”
（不过用i和i-1应该更好理清）


### 代码

```java
class Solution {
    public String countAndSay(int n) {

        if(n==1) return "1";

        
        
        String newString = countAndSay(n-1);
        StringBuilder result = new StringBuilder();
        
        int begin = 0;
        int count = 1;
        for(int i=0;i<newString.length();i++){
            if(i+1<newString.length()&&newString.charAt(i+1)==newString.charAt(i)){
                count++;

            }else{
                // ①若最后一个和倒数第二个不相等，在上一个循环里把倒数第二个的情况就加进去了
                //   这次循环就只需要加“1”个“最后的数”
                // ②若最后一个数和倒数第二个相等，最后一个数的次数也已经加上去了，也就只用加“count”个“最后的数”
                result.append(count+"").append(newString.charAt(i));
                count = 1;
            }
            
        }
        
        
        return result.toString();

    }
}
```