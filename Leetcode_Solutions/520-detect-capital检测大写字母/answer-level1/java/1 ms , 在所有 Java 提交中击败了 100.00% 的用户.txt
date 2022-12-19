### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean detectCapitalUse(String word) {
        int count = 0;
        int index = -1;
        char[] ca = word.toCharArray();
        for(int i = 0;i<ca.length;i++){
            if(ca[i]>=65&&ca[i]<=90){
                count++;
                index = i;
            }
        }
        if(count==ca.length||count==0||(count==1&&index==0)){
            return true;
        }
        return false;
    }
}
```