### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/f6ae21a45fbf318e448a807025f54f5517f07a82289145a41e68b30e394e0e26-image.png)

### 代码

```java
class Solution {
    public int[] numberOfLines(int[] widths, String S) {
        int []  ans = new int[]{1,0};
        for(char c:S.toCharArray()){
            ans[1]+=widths[c - 'a'];
            if(ans[1] > 100){
                 ans[0]++;ans[1] = widths[c - 'a'];
            }
            if(ans[1] == 100){
                ans[0]++;ans[1] = 0;
            }
        }
        return ans;
    }
}
```