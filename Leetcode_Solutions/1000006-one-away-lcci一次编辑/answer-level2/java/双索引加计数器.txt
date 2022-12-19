### 解题思路

最开始忽略了字符串剩余字符，后面加上，完美解决
### 代码

```java
class Solution {
    public boolean oneEditAway(String first, String second) {
        int len1 = first.length();
        int len2 = second.length();
        if(len1 - len2 > 1 || len1 - len2 < -1) { //最多执行一次操作，长度差不能大于1
            return false;
        }
        int index1 = 0, index2 = 0;
        int count = 0;
        while(index1 < len1 && index2 < len2) {
            if(second.charAt(index2) == first.charAt(index1)) {
                index1++;
                index2++;
            } else if(index1 + 1 < len1 && first.charAt(index1 + 1) == second.charAt(index2)){
                index1++;
                count++;
            } else if(index2 + 1 < len2 && first.charAt(index1) == second.charAt(index2 + 1)){
                index2++;
                count++;
            } else {
                index1++;
                index2++;
                count++;
            }
        }
        //两个字符串剩余字符与修改次数的和小于2
        return count + Math.abs(index1 - len1) + Math.abs(index2 - len2) < 2;
    }
}
```