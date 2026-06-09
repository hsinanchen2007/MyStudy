### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] ans = new int[seq.length()];
        int index = 0;
        int countLeft = 0;
        int countRight = 0;
        for(char c: seq.toCharArray()){
            if(c == '('){
                ans[index++] = countLeft++%2 == 0? 0: 1;
            }
            else{
                ans[index++] = countRight++%2 == 0? 0: 1;
            }
        }
        return ans;
    }
}
```