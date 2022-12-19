![1586010750(1).jpg](https://pic.leetcode-cn.com/8af71a43132da010aefd4694425556a1b53dcdddb5e1a6722748d52f7f798214-1586010750\(1\).jpg)


```
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        we : for (int[] arr : matrix){
            for (int i = 0;i < arr.length ;i++){
                if (arr[i] == target){
                    return true;
                } else if (arr[i] > target){
                    continue we;
                }
            }
        }
        return false;
    }
}
```