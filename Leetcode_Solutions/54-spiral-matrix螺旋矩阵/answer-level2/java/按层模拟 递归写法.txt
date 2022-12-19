### 解题思路
先遍历最外一层矩阵，在遍历内一层

### 代码

```java
class Solution {
   List<Integer> list = new ArrayList<>();
    int maxSize;
    public List<Integer> spiralOrder(int[][] matrix) {
        int h = matrix.length;
        if(h == 0){
            return list;
        }
        int l = matrix[0].length;
        maxSize = h*l;
        list.clear();
        spiralOrder(matrix,0,h-1,0,l-1);
        return list;
    }
    private  void spiralOrder(int[][] matrix,int minx,int maxx,int miny,int maxy){
        if (list.size() >= maxSize ){
            return;
        }
        if (minx >= maxx && miny == maxy){
            add(matrix[minx][miny]);
            return;
        }
       //遍历最上面一行
        for (int i=miny;i<=maxy;i++){
            add(matrix[minx][i]);
        }
       // 遍历最右边列
        for (int i=minx+1;i<=maxx;i++){
            add(matrix[i][maxy]);
        }
//遍历最下面一行
        for (int i=maxy-1;i>= miny;i--){
            add(matrix[maxx][i]);
        }
//遍历最左面一列
        for (int i=maxx-1;i>=minx+1;i--){
            add(matrix[i][miny]);
        }
// 遍历内层
        spiralOrder(matrix,minx+1,maxx-1,miny+1,maxy-1);

    }
    private void add(int value){
        if (list.size() >= maxSize){
            return;
        }
        list.add(value);
    }
}
```