### 解题思路
先把海洋和陆地分开存储，然后遍历海洋，求出当前海洋到陆地最短的距离。最后得出这些最短距离中的最大值

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        List<Integer> landx=new ArrayList();
        List<Integer> landy=new ArrayList();
        List<Integer> oceanx=new ArrayList();
        List<Integer> oceany=new ArrayList();
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==0){
                    oceanx.add(i);
                    oceany.add(j);
                }else{
                    landx.add(i);
                    landy.add(j);
                }
            }
        }
        int md=0;
        for(int i=0;i<oceanx.size();i++){
            int ox=oceanx.get(i);
            int oy=oceany.get(i);
            int min=200;
            for(int j=0;j<landx.size();j++){
                int lx=landx.get(j);
                int ly=landy.get(j);
                int cur=Math.abs(ox-lx)+Math.abs(oy-ly);
                if(cur<min) min=cur;
            }
            if(min>md) md=min;
        }
        if(md==200) md=-1;
        if(md==0) md=-1;
        return md;
    }

}
```