提交结果：
![image.png](https://pic.leetcode-cn.com/b250d1905bdc37bad7114209ebbc699de2c70de0a7bea8ce4c9f516d7a8a66c6-image.png)


直接贴代码：
```
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if ( s1 == null || s2 == null ) {
            return false;
        }
        char c1[] = s1.toCharArray();
        char c2[] = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        return String.valueOf(c1).equals( String.valueOf(c2) );
    }
}
```
