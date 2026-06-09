
### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int rear = -1;
        int n = seq.length();
        int ans[] = new int[n];
        for(int i = 0;i<n;i++){
            if(seq.charAt(i)=='(')
                ans[i]=++rear&1;
            else
                ans[i]=rear--&1;
        }
        return ans;
    }

}
```