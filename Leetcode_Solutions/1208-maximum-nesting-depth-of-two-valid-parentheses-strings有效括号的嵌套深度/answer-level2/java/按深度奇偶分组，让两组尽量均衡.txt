### 解题思路
张腾同学的思路理解起来比较简单，参考实现的。

Seq = ( ( ) ( ( ) ) ( ) )
嵌套深度 = [ 1, 2, 2, 2, 3, 3, 2, 2, 2, 1]
分组情况 = [ A, B, B, B, A, A, B, B, B, A]

输出 = [ 0, 1, 1, 1, 0, 0, 1, 1, 1, 0]

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        char[] arr = seq.toCharArray();

        int size = arr.length;
        int depth = 1;
        int[] ans = new int[size];
        for(int i=0; i<size; i++) {
            if(arr[i] == '(') {
                ++depth;
                ans[i] = depth % 2;
            } else {
                ans[i] = depth % 2;
                --depth;
            }
        }

        return ans;
    }
}
```