按题目的要求，右下左上遍历数组。分布定义四个边界up = 0, right = matrix[0].length - 1, down = matrix.length - 1, left = 0;当超过边界就要改变方向，遍历完一行或一列，相应的边界就会缩小。

```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer > ans = new ArrayList<Integer >();
        if(matrix.length == 0) return ans;
        int i = 0, j = 0, z = 0, Count = matrix.length * matrix[0].length;
        int up = 0, right = matrix[0].length - 1, down = matrix.length - 1, left = 0;
        while(z < Count){
            while(j <= right){//右
                ans.add(matrix[i][j++]);
                ++z;
            }
            if(z >= Count) break;
            --j;//循环结束时，j超出了边界，需要回退回来
            ++i;//跳到一个新的值上面，不自增最后一个值就会重复
            ++up;//因为第一行遍历完毕，上边界从0变到1
            while(i <= down){//下
                ans.add(matrix[i++][j]);
                ++z;
            }
            if(z >= Count) break;
            --i; --j; --right;
            while(j >= left){//左
                ans.add(matrix[i][j--]);
                ++z;
            }
            if(z >= Count) break;
            --i; ++j; --down;
            while(i >= up){//上
                ans.add(matrix[i--][j]);
                ++z;
            }
            if(z >= Count) break;
            ++i; ++j; ++left;
        }
        return ans;
    }
}
```
