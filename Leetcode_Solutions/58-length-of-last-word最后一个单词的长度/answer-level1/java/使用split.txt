### 解题思路
用的split分割存入数组，然后读出数组最后一个单词长度

另外小白求问：为啥split前面不加trim就会报错呀

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        if(s.isEmpty()){
            return 0;
        }
        else {
        s = s.trim();
        String arr[]=s.split(" ");
        String s1=arr[arr.length-1];
        return s1.length();

        }
    
        
    }
}
```