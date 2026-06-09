### 解题思路
此处撰写解题思路
自己写的将字符串先转成字符数组，然后将顺序交换，先交换n之前的，然后交换n之后的，最后整个交换，当然顺序之间可以交换
### 代码

```java
class Solution {
    public String reverseLeftWords(String s, int n) {
        int len = s.length()-1;
        char[] chars = s.toCharArray();
        solve(chars,0,n-1);
        solve(chars,n,len);
        solve(chars,0,len);
        return String.valueOf(chars);
    }

    public void solve(char[] chars, int start, int end){
        while(start < end){
            char temp = chars[end];
            chars[end] = chars[start];
            chars[start] = temp;
            start++;
            end--;
        }
    }
}
```
