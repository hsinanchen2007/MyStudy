### 解题思路
面试能有这种题目才有鬼哩，大家姑且看看吧，面试不会这么简单的

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        char[] arr = s1.toCharArray();
        char[] brr = s2.toCharArray();
        Arrays.sort(arr);
        Arrays.sort(brr);

        if(new String(arr).equals(new String(brr))) return true;
        return false;
    }
}
```