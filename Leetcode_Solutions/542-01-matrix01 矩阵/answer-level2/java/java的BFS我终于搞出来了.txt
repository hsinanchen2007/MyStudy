### 解题思路
此处撰写解题思路
昨天有一个错误一直找不出来，今天终于找出来了，可，又超时了，真是气死我了。
然后看了大家的解题思路，看着敲了一下，然后终于对了。
我一开始是一个元素用一个搜索，不超时难怪呢。
现在想想，把所有相应的元素都进队，然后在统一更新，这样快多了。
### 代码

```java
class Solution {
    public int[][] updateMatrix(int[][] matrix) {
        int m=matrix.length;
        int n=matrix[0].length;
        int[][]move={{0,1},{0,-1},{1,0},{-1,0}};
        Queue<int[]>queue=new LinkedList<>();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0)
                 queue.offer(new int[]{i,j});
                if(matrix[i][j]==1)
                 matrix[i][j]=10001;
            }
        }
        while(!queue.isEmpty()){
            int size=queue.size();
            while(size>0){
                size--;
                int[]a=queue.poll();
                int ti=a[0],tj=a[1];
                for(int[]mm:move){
                    int tti=ti+mm[0];
                    int ttj=tj+mm[1];
                    if(tti>=0&&ttj>=0&&tti<m&&ttj<n&&matrix[tti][ttj]>matrix[ti][tj]+1){
                        matrix[tti][ttj]=matrix[ti][tj]+1;
                        queue.offer(new int[]{tti,ttj});
                    }
                }

            }
        }
        return matrix;
    }
}
```