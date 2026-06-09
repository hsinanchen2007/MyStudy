### 解法一 
1. 因为学生数就等于N，所以我们可以通过学生A来进行查找学生A的所有朋友
2. 找到学生A的朋友B后，再以B进行查找，查找B的朋友，因为友谊具有传递性，所以他们都可以形成同一个朋友圈
3. 并且已经遍历过的学生无需再遍历，因为已经是在之前的朋友圈里面了
```
class Solution {
    public int findCircleNum(int[][] M) {
        int length=M.length;
        if(length==0) return 0;
        int count=0;
        for(int n=0;n<length;n++){//总共有n名学生
            if(M[n][n]==1){ //直接找学生，为1说明还没有成为记录过的学生
                DFSfindF(n,M);//以这名学生开始遍历他的朋友
                count++;
            }
        }
        return count;
    }

    private void DFSfindF(int n,int[][] M){
        if(M[n][n]==0) return;
        M[n][n]=0;//记录这个人已经遍历过,因为M[n][n]是必定等于1的，为0则说明已经遍历过
        //查找遍历这个人的朋友
        for(int i=0;i<M.length;i++){
            //遍历其他同学，看看是否跟他是朋友
            if(M[n][i]==1){//找到n的朋友i，再递归查找i的朋友
                DFSfindF(i,M);
            }
        }
    }
}
```

### 解法二 并查集
1. 并查集可以用来合并不同圈子的，默认元素是自己指向自己。
2. 比如这道题，元素就是每个学生，一开始学生自己就是一个独立的朋友圈。
3. 然后在遍历的过程中，比如发现A与B是朋友关系，则合并A和B的朋友圈形成一个。
4. 这时候如果发现B和C，直接合并B，C朋友圈，这个时候A、B、C就会成为一个圈子。
```
class Solution {
    
    public int findCircleNum(int[][] M) {
        int length=M.length;
        if(length==0) return 0;
        UnionFind unionF=new UnionFind(length);
        for(int row=0;row<length;row++){
            for(int col=row+1;col<length;col++){
                //这边只需要遍历row后面的朋友即可，因为前面的朋友关系已经遍历过。
                if(M[row][col]==1){
                    //如果为1说明是朋友关系，合并朋友圈
                    unionF.unionF(row,col);
                }
            }
        }
        return unionF.count;
    }
}
//并查集，用来存储每个学生的关系，默认每个学生自己是单独的朋友圈。

public class UnionFind{
    int[] roots;
    int count;//朋友圈数量
    public UnionFind(int n){
        roots=new int[n];//初始化，学生关系，每个学生默认只跟自己是朋友
        for(int i=0;i<n;i++){
            roots[i]=i;
            count++;//默认每个学生是独立的朋友圈，则学生数量就是朋友圈数量。
        }
    }
    //找朋友关系
    public int findF(int n){
        int root=n;
        while(roots[root]!=root){//找到连接的朋友关系
            root=roots[root];
        }
        //路径压缩,将可以成为朋友的，都依次指向root，这样缩短了层次，只有两层
        while(roots[n]!=n){
            int temp=roots[n];
            roots[n]=root;
            n=temp;
        }
        return root;
    }
    //表示b和p是好朋友，需要合并他们朋友圈
    public void unionF(int b,int p){
        int rootB=findF(b);
        int rootP=findF(p);
        if(rootB!=rootP){//他们当前不是好朋友，则合并
            roots[rootB]=rootP;
            count--;//没合并一个学生，则朋友圈减少一个
        }
    }
}
```

