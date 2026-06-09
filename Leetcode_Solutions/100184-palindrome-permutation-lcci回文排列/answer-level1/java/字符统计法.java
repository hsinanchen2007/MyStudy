### 解题思路
  先统计每个字符出现的次数，如果出现奇数次的字符大于1次，则为false

### 代码

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        int oddNum = 0;
        int[] temp = new int[128];
        for(int i=0;i<s.length();i++){
            temp[s.charAt(i)] ++;
        }
        for(int i=0;i<temp.length;i++){
            if((temp[i] & 1 )== 1){
                oddNum ++;
            }
        }
        if(oddNum > 1){
            return false;
        }
        return true;
    }
}
```