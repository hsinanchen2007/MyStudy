### 解题思路
第一念头就是需要嵌套for循环遍历所有的元素，然后0与1对换。

为了实现左右反转，创建了新的二维数组ans，只要反过来保存元素就可以了。

需要注意的是l2 - j - 1那部分，例如j是第0个元素，l2 - 0 - 1就是最后一个元素，以此类推。

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int l1 = A.length;
        int l2 = A[0].length;

        int[][] ans = new int[l1][l2];

        for(int i = 0; i < l1; i++){
            for(int j = 0; j < l2; j++){
                ans[i][l2 - j - 1] = A[i][j] ^ 1;
            }
        }
        return ans;
    }
}
```