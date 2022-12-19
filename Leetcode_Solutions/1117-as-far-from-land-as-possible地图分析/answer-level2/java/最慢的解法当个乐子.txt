### 解题思路
将所有海洋到所有陆地的距离找到，比较即可，太慢了，哈哈，写代码就图一乐
![image.png](https://pic.leetcode-cn.com/9aef93fe3ae21e22f4588c81721ca44389e8aa46a135a85965e8ae807f06e0fa-image.png)
![NV6G\]@`5YRO}$5LXWXWD@Q1.png](https://pic.leetcode-cn.com/2adc1a6aa9954f3ff3d93d2a54af74e957bb8a63eca044543a7ed76a761d84ea-NV6G%5D@%605YRO%7D$5LXWXWD@Q1.png)

### 代码

```java
class Solution {
    class Node{
        int x;
        int y;
        Node(int x,int y){this.x=x;this.y=y;}
    }
    public int maxDistance(int[][] grid) {
        // 存储海洋区域到陆地区域的最小值
        int n=grid.length;
        int[][] minLength=new int[n][n];
        // 海洋
        List<Node> ocean=new ArrayList<>();
        // 陆地
        List<Node> land=new ArrayList<>();
        // 最远距离
        int maxLength=0;
        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[i].length;j++){
                if(grid[i][j]==0){
                    ocean.add(new Node(i,j));
                } else{
                    land.add(new Node(i,j));
                }
            }
        }
        if(ocean.size()==0||land.size()==0){
            return -1;
        }
        for(int j=0;j<ocean.size();j++){
            Node o=ocean.get(j);
            minLength[o.x][o.y]=Math.abs(o.x-land.get(0).x)+Math.abs(o.y-land.get(0).y);
            for(int i=0;i<land.size();i++){
              if(minLength[o.x][o.y]>(Math.abs(o.x-land.get(i).x)+Math.abs(o.y-land.get(i).y))){
                   minLength[o.x][o.y]=Math.abs(o.x-land.get(i).x)+Math.abs(o.y-land.get(i).y);
               }
            }
            if(minLength[o.x][o.y]>maxLength){
                maxLength=minLength[o.x][o.y];
            }
        }
        return maxLength;

    }
}
```