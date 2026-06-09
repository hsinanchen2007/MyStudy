### 解题思路
太巧秒了！！！

脑子直直的想法就是将每个元素加上之后，再看奇数的数量。

看了一个讨论，发现太妙了。有以下几点：

1. 奇 偶的加减可以转变成boolean的true 和 false
2. 行列的加减可以统一用两个数组解决
3. 最后根据公式（规律）来得出奇偶的数量

最后得到的是rr * m + cc * n - rr * cc * 2，原本行列奇数的数量相加为rr * m + cc * n - rr * cc，但是当行列同时为奇数时，重叠部分就成了偶数了。

所以 最后的结果是rr * m + cc * n - rr * cc * 2

*从求几何面积考虑就知道了，横向面积 + 纵向面积 - 2*横纵重合面积 将单元格设为一个单位，rr表示在多少行上有阴影，cc表示在多少列上有阴影， 阴影面积就为： rr * m + cc * n - rr * cc 但是横纵重合部分是偶数的，所以需要再减去重合部分得到：rr * m + cc * n - 2*rr * cc by @1900*

### 代码

```java
class Solution {
    public int oddCells(int n, int m, int[][] indices){
        boolean[] r = new boolean[n];
        boolean[] c = new boolean[m];

        for(int i = 0; i < indices.length; i++){
            r[indices[i][0]] = !r[indices[i][0]];
            c[indices[i][1]] = !c[indices[i][1]];
        }

        int rr = 0, cc = 0;
        for(int i = 0; i < r.length; i++){
            if(r[i]) rr++;
        }

        for(int i = 0; i < c.length; i++){
            if(c[i]) cc++;
        }
        
        return rr * m + cc * n - rr * cc * 2;
    }
}

// class Solution {
//     public int oddCells(int n, int m, int[][] indices) {

//         int ans = 0;

//         int[][] matrix = new int[n][m];

//         for(int[] arr : indices){
            
//             for(int i = 0; i < m; i++){
//                 matrix[arr[0]][i]++;
//             }

//             for(int j = 0; j < n; j++){
//                 matrix[j][arr[1]]++;
//             }
//         }

//         for(int i = 0; i < n; i++){
//             for(int j = 0; j < m; j++){
//                 if(matrix[i][j] % 2 != 0)
//                     ans++;
//             }
//         }
//         return ans;
//     }
// }
```