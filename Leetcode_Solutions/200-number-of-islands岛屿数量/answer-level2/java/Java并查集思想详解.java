这道题目效率最高的还是BFS或者DFS，但是技多不压身，还是要学习一下并查集的思想，但是我发现题解中都讲解的不是很清楚，所以想按照自己的想法总结一下，给需要学习并查集的人一些帮助。
下面是一个我觉得讲解并查集非常好的一个文章，建议可以看一下
[https://blog.csdn.net/qq_41593380/article/details/81146850]()
并查集思想的总结：
（1）初始化一个长度为n的数组，数组里面存储的是该元素的父亲的角标。
（2）如果两个不同祖先的节点合并，只需要把这两个节点的祖先选出来一个作为共同的祖先就可以。代码中的union方法
（3）代码中的findparent方法，寻找一个节点的祖先；
（4）最后遍历数组，有多少个祖先，就有多少个岛屿。
```

    public int numIslands(char[][] grid) {
        if(grid == null || grid.length == 0) return 0;
        //初始化并查集的数组
        int[] arr = new int[grid.length *grid[0].length];
        //初始-1，代表根节点
        Arrays.fill(arr,-1);
        for(int i = 0; i <grid.length;i++){
            for(int j = 0 ; j < grid[i].length;j++){
                if(grid[i][j] =='1'){
                    //沉岛思想，把遍历过的岛屿赋值为0
                    grid[i][j] = 0;
                    //如果下面是陆地需要联合起来
                    if(i +1 < grid.length && grid[i+1][j] =='1'){
                        union(arr,i*grid[i].length+j,(i+1)*grid[i].length+j);
                    }
                    //如果右边是陆地联合起来
                    if(j +1 < grid[i].length && grid[i][j+1] =='1'){
                        union(arr,i*grid[i].length+j,i*grid[i].length+j+1);
                    }
                }else{
                    //把海洋变成-2
                    arr[i*grid[i].length+j] = -2;
                }
            }
        }
        //计算数组中有有多少个根节点，就有多少个岛屿
        int count = 0;
        for(int num : arr) {
            if(num == -1) count++;
        }
        return count;
    }
   private void union(int[] arr,int i,int j){
        //第一个父节点
        int x = findparent(arr,i);
        //第二个父节点
        int y = findparent(arr,j);
        //如果两者的父节点不相等，需要把两者结合起来
        if(x !=y){
            arr[y] = x;
        }
   }
   private int findparent(int[] arr,int node){
       //找到最终父节点，返回父节点的index
       if(arr[node] ==-1){
           return node;
       }
       //继续寻找父节点
      return findparent(arr,arr[node]);
   }
```
