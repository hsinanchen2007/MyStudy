### 解题思路
本题是使用**双指针法**，一左一右依次遍历整个字符串

通过while循环先将不满足题意的情况给排除掉，剩下的可以都转化成小写或大写进行比较，最终得到结果。
### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            //过滤掉不是字母或数字的元素
            while(l < r && !Character.isLetterOrDigit(s.charAt(l))){
                l++;
            }
            while(l < r && !Character.isLetterOrDigit(s.charAt(r))){
                r--;
            }
            //都转化成小写进行比较
            if(Character.toLowerCase(s.charAt(l)) != Character.toLowerCase(s.charAt(r))){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
}
```