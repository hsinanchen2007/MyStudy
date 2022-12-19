### 解题思路
直接排序
![image.png](https://pic.leetcode-cn.com/f463623bd6075f2ce0037e2e4947583a60a622f8065f2e6151c01890ee21dd34-image.png)


### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        String str1 = new String(c1);
        String str2 = new String(c2);
        if(str1.equals(str2)){
            return true;
        }else{
            return false;
        }
    }
}
```