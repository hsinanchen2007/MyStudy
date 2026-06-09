这个题可以很容易的使用双指针来解决。

i指向数组的第一个元素，j指向数组的最后一个元素。每次交换i和j的两个位置的元素，然后将i向左移动一步，j向右移动一步即可。

```java
class Solution {
    public void reverseString(char[] s) {
        int i = -1, j = s.length;
        while(++i < --j){
            swap(s, i, j);
        }
    }
    
    private void swap(char[] s, int i, int j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}
```

