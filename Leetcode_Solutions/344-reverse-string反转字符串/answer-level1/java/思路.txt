### 解题思路
此处撰写解题思路
我的思路:
    字符串截取成字符进行计较
    遍历字符串长度的一半就行，前面的往后递增，后面的往前面递减，一直进行交换
    
### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        for(int i=0;i<s.length/2;i++){
           char k=s[i];
           s[i]=s[s.length-i-1];
           s[s.length-i-1]=k;
        }
    }
}
```