### 解题思路
直接替换即可。

### 代码

```java
class Solution {
    public void reverseString(char[] s) {
        int length = s.length;
        int left = 0;
        int right = s.length - 1;
        while (left <= right){
            swap(s, left++, right--);
        }
    }

    // swap s[i] and s[j]
    public void swap(char[] s, int i, int j){
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
```