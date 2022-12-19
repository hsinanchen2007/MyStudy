### 解题思路
没什么难度，直接从后往前遍历即可。

### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int count=0;
        for(int i=s.length()-1;i>-1;i--){
            if(s.charAt(i)==' '){
                if(count!=0)
                    return count;
            }else{
                count++;
            }
        }
        return count;
    }
}
```