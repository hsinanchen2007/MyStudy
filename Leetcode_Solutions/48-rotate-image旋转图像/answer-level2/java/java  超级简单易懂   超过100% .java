### 解题思路
矩形的旋转本质就是坐标位置的互换，由于题目中是n x n的矩形，所以旋转的复杂度被大大简化了，只需找一下旋转中位置替换的规律即可，如图，图中会发送颜色互换的坐标我用相同颜色标注出来了，由于是顺时针旋转，那么位置就是顺时针替换（如果改成旋转180度或者逆时针旋转之类的都类似）
![微信图片_20200403223616.png](https://pic.leetcode-cn.com/0631fd0bda50d6be85de12f9fb3fccb2a649505778e69847abf298fd24b17478-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200403223616.png)

这只是外层一圈的替换，再依次把所有层的都一起替换即可，注意考虑n等于奇数或者偶数时的边界值情况


### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if(matrix == null)  return;

        int n = matrix.length-1;
        
        int r = 0;
        int temp = 0;
        //旋转的层数
        while(r <= n/2){
            
            //依次旋转这一层的所有数
            for(int i=r; i<=n-r-1; i++){
                temp = matrix[r][i];
                matrix[r][i] = matrix[n-i][r];
                matrix[n-i][r] = matrix[n-r][n-i];
                matrix[n-r][n-i] = matrix[i][n-r];
                matrix[i][n-r] = temp;
            }
            r++;
        }
        
    }
}
```