### 解题思路
通过存储行和列的服务器数量，然后通过行遍历，去除多余统计，然后得到结果。

### 代码

```java
class Solution {
    class Node{
        int x;
        int y;
        Node(int x,int y){this.x=x;this.y=y;}
    }
    public int countServers(int[][] grid) {
        Map<Integer,List<Node>> xmap=new HashMap<>();
        Map<Integer,List<Node>> ymap=new HashMap<>();

        for(int i=0;i<grid.length;i++){
            for(int j=0;j<grid[0].length;j++){
                if(grid[i][j]==0) continue;
                List<Node> xnode=xmap.computeIfAbsent(i,k->new ArrayList<>());
                List<Node> ynode=ymap.computeIfAbsent(j,k->new ArrayList<>());
                Node node=new Node(i,j);
                xnode.add(node);
                ynode.add(node);
            }
        }
        int count=0;
        for(int i=0;i<grid.length;i++){
            // 没有点
            if(!xmap.containsKey(i)){
                continue;
            }
            
            List<Node> nodeList=xmap.get(i);
            // 有一个点
            if(nodeList.size()==1){
                List<Node> yNodeList=ymap.get(nodeList.get(0).y);
                if(yNodeList.size()==1){
                    continue;
                } else{
                    count++;
                }
            } else{
                // 有两个点以上
                count+=nodeList.size();
            }

        }
        return count;
    }
}
```