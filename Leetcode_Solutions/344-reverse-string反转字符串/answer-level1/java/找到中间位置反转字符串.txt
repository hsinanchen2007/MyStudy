### 解题思路
执行用时 :1 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :52.8 MB, 在所有 java 提交中击败了71.47%的用户
### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int k = s.length;
        for(int i =0;i<k/2;i++){
            char temp = s[i];
            s[i] =s[k-1-i];
            s[k-1-i] =temp;
        }
    }
}
```