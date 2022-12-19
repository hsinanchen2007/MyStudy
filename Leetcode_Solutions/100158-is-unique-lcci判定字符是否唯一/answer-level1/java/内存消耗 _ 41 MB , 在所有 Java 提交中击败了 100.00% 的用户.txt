### 解题思路
java 中某种意义上讲 char 可以等价于 int
构建一个int[]，用每一个char 做下标用来记录出现的 astr中出现过的次数，如果超过0就出现过返回false

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        var count = new int[65535];
        for(int i = 0;i<astr.length();i++){
            char c = astr.charAt(i);
            if(count[c]>0){
                return false;
            }else{
                count[c] = 1;
            }
        }
        return true;
    }
}
```