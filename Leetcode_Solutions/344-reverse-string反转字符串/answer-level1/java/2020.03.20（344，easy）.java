### 解题思路
本题思路很简单，通过**双指针法**依次遍历整个数组，用while循环控制边界，再依次交换数据即可。

### 代码

```java
class Solution {
    public void reverseString(char[] s) {       
        int l = -1;
        int n = s.length;
        while(++l < --n){
            char c = s[l];
            s[l] = s[n];
            s[n] = c;
        }
        return ;
    }
}
```