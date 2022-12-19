### 解题思路
暴力解法，一步步模拟当前会遇到的情况
一开始向右走，每加一个数把当前数变为最小值，遇到边界或最小值向下走，
再遇到边界或最小值向左走，依次。
直到循环到最后一圈该开始向右了那个值是最小值，跳出。
此时最后一个值没有写入，再加入即可。
![微信图片_20200131135732.png](https://pic.leetcode-cn.com/ca29c1afad1708d7fa9240410420184ef3e15ef5ac24104901dcaa72f8b9af42-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200131135732.png)

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer>list=new ArrayList<>();
        if (matrix.length<=1 ||matrix[0].length<=1){
            for (int []i:matrix){
                for (int j:i)
                    list.add(j);
            }
            return list;
        }
        int i=0,j=0;
        do{
            while (j<matrix[0].length){
                if (j+1==matrix[0].length || matrix[i][j+1]==Integer.MIN_VALUE)
                    break;
                list.add(matrix[i][j]);
                matrix[i][j]=Integer.MIN_VALUE;
                j++;
            }
            while (i<matrix.length){
                if (i+1==matrix.length || matrix[i+1][j]==Integer.MIN_VALUE)
                    break;
                list.add(matrix[i][j]);
                matrix[i][j]=Integer.MIN_VALUE;
                i++;
            }
            while (j>=0){
                if (j-1<0 || matrix[i][j-1]==Integer.MIN_VALUE)
                    break;
                list.add(matrix[i][j]);
                matrix[i][j]=Integer.MIN_VALUE;
                j--;
            }
            while (i>=0){
                if (i-1<0 || matrix[i-1][j]==Integer.MIN_VALUE)
                    break;
                list.add(matrix[i][j]);
                matrix[i][j]=Integer.MIN_VALUE;
                i--;
            }
        }while (matrix[i][j+1]!=Integer.MIN_VALUE);
        list.add(matrix[i][j]);
        return list;
    }
}
```