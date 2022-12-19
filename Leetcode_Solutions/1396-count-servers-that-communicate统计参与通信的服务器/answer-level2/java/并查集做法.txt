先把01矩阵转化成有服务器的坐标集合，然后遍历，如果两台服务器x轴或者y轴相同就合并它们。最后找到各个集合，如果集合中服务器个数大于1，就加到结果中。
```
class Solution {
    int [] parent;
    int [] num;
    public int countServers(int[][] grid) {
        int m=grid.length;
        int n=grid[0].length;
        //转化成有服务器所在的坐标集合
        List<int []> coordinate=new ArrayList<>();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1){
                    int [] t=new int[]{i,j};
                    coordinate.add(t);
                }
        int len=coordinate.size();
        parent=new int[len];
        num=new int[len];
        for(int i=0;i<len;i++){
            parent[i]=i;
            num[i]=1;
        }
        //如果两台服务器的x轴或者y轴相同，则合并它们
        boolean [] flags=new boolean[len];
        for(int i=0;i<len;i++)
            for(int j=0;j<len;j++)
                if(i!=j&&!(flags[i]&&flags[j])&&(coordinate.get(i)[0]==coordinate.get(j)[0]||coordinate.get(i)[1]==coordinate.get(j)[1])){
                    union(i,j);
                    flags[i]=true;
                    flags[j]=true;
                }
        //计算每个集合的服务器个数，大于1才说明能与其他服务器通信
        int sum=0;
        for(int i=0;i<len;i++)
            if(i==parent[i]&&num[i]>1)
                sum+=num[i];
        return sum;
    }
    private int find(int root){
        while(root!=parent[root]){
            parent[root]=parent[parent[root]];
            root=parent[root];
        }
        return root;
    }
    private void union(int x, int y){
        int root1=find(x);
        int root2=find(y);
        parent[root1]=root2;
        num[root2]+=num[root1];
    }
}
```

