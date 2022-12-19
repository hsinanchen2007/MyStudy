### 解题思路
递归调用代码，比较简单，就是把逻辑写出来就好。CountAndSay 
时间复杂度不太会算应该是O（N ^ 2）
空间复杂度使用了n个系统栈为O(N)
### 代码

```java
class Solution {
    public String countAndSay(int n) {
    if(n == 1) return "1";
    String s = countAndSay(n - 1);
    int count = 1;
    String a = "";
    for(int i = 1 ; i < s.length() ; i++){
        if(s.charAt(i) == s.charAt(i-1)){
            count++;
        }else{
            a += "" + count + s.charAt(i - 1);
            count = 1;
        }
    }
    a += "" + count + s.charAt(s.length() - 1);
    return a;
    }
}
```