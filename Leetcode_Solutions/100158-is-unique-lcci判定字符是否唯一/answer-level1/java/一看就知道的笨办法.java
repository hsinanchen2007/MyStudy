### 解题思路
比较笨的办法，2个循环；只要找到一个重复的就跳出2层循环，配合continue使用。执行时间和内存消耗都是100%
### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] str = astr.toCharArray();
        boolean flag = true;
        label1:for(int i = 0; i<str.length-1;i++){
            for(int j = i+1;j<str.length;j++){
                if(str[i] == str[j]){
                    flag = false;
                     continue label1;
                }
            }
        }
        return flag;
    }
}
```