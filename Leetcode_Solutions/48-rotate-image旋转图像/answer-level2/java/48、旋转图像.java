### 解题思路
![微信图片_20200221165848.jpg](https://pic.leetcode-cn.com/db529e9216cd2da1fa6d73f135c665c53bdf696cbbf161efe370de9a4aea2aae-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200221165848.jpg)


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if(n == 1){
            return;
        }
        for(int i = 0; i < n / 2; i ++){
            for(int j = i; j < n - 1 - i; j ++){
                int tmp = matrix[j][n - 1 - i];
                matrix[j][n - 1 -i] = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n-1-i][n-1-j] = tmp;
            }
        }
        return;       
    }
}
```