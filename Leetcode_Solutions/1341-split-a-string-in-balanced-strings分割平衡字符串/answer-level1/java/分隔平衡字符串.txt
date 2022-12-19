### 解题思路
一次遍历，遇到L则计数 l++,否则计数 r++,若l == r,则计数count++,归零l和r

### 代码

```java
class Solution {
    public int balancedStringSplit(String s) {
        int l = 0;
        int r = 0;
        int count = 0;
        for(char c : s.toCharArray()){
            if(c == 'L'){
                l++;
            }else {
                r++;
            }
            if(l == r){
                count ++;
                l = 0;
                r = 0;
            }
        }
        return count;
    }
}
```