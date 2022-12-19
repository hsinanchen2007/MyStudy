### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] ans = new int[seq.length()];
        int idx = 0;
        for(char c: seq.toCharArray()){
            ans[idx++] = c =='('?idx&1:((idx+1)&1);
        }

        return ans;

    }
}
```