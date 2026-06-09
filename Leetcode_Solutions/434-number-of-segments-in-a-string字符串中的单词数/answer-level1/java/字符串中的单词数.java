### 解题思路
Java语言的语法题，将字符串按空格分割成字符串数组，判断每个数组是不是空的就行。

### 代码

```java
class Solution {
    public int countSegments(String s) {
        
        int count=0;
        String[] strs=s.split(" ");
        for(String str:strs)
        {
            if(!"".equals(str))
                count++;
        }
        return count;
    }
}
```