### 解题思路
除了当前字符判断这个字符串还有没有和自己一样的字符。
![image.png](https://pic.leetcode-cn.com/a74067471ca9d2c1038a0091da1015be441fe2c76db1603a42cd3f0c8ed83333-image.png)

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for(int i=0;i<astr.length();i++){
            if(astr.lastIndexOf(astr.charAt(i))!=i){
                return false;
            }
        }
        return true;
    }
}
```