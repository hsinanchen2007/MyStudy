### 解题思路
双指针
执行用时 :1 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :43.1 MB, 在所有 Java 提交中击败了99.75%的用户

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        if(s.length <= 1)   return;
        int left = 0;
        int right = s.length - 1;
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left ++;
            right --;
        }
        return ;
    }
}
```