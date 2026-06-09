### 解题思路
自己写的小型图库工具类，还在完善中

### 代码

```java
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Graph {
    private int E,V;
    private TreeSet<Integer>[] adjList;
    private boolean hasLoop = false;

    public Graph(String fileName){
        File file = new File(fileName);
        try(Scanner sc = new Scanner(file)){
            V = sc.nextInt();
            adjList = new TreeSet[V];
            for(int i=0;i<V;i++){
                adjList[i] = new TreeSet<>();
            }
            E = sc.nextInt();
            for(int i=0;i<E;i++){
                int a = sc.nextInt();
                int b = sc.nextInt();
                adjList[a].add(b);
                adjList[b].add(a);
            }
        }catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }
    public Graph(int [][] adjList){
        V = adjList.length;
        this.adjList = new TreeSet[V];
        for(int i=0;i<V;i++){
            this.adjList[i] = new TreeSet<>();
        }
        for(int i=0;i<V;i++){
            for(int j=0;j<adjList[i].length;j++){
                this.adjList[i].add(adjList[i][j]);
                E++;
            }
        }
        E /= 2;
    }

    public int V(){
        return V;
    }

    public int E(){
        return E;
    }

    //返回两个顶点之间是否存在边
    public boolean hasEdge(int v1,int v2){
        return adjList[v1].contains(v2);
    }

    //返回一个含有该顶点所有邻边迭代器
    public Iterator<Integer> adj(int v){
        return adjList[v].iterator();
    }

    //dfs
    public ArrayList<Integer> dfs(int v){
        ArrayList<Integer> al = new ArrayList<>();
        boolean[] b = new boolean[V];
        dfs(al,v,b);
        for(int i=0;i<V;i++){
            if(!b[i]){
                dfs(al,i,b);
            }
        }
        return al;
    }
    private void dfs(ArrayList<Integer> al,int v,boolean[] b1){
        b1[v] = true;
        al.add(v);
        Iterator<Integer> i = adj(v);
        while(i.hasNext()){
            int v1 = i.next();
            if(!b1[v1]){
                dfs(al,v1,b1);
            }
        }
    }
    private void dfs(int v,boolean[] b1){
        b1[v] = true;
        Iterator<Integer> i = adj(v);
        while(i.hasNext()){
            int v1 = i.next();
            if(!b1[v1]){
                dfs(v1,b1);
            }
        }
    }
    private void dfs(int v,int[] i1,int a){
        i1[v] = a;
        Iterator<Integer> i = adj(v);
        while(i.hasNext()){
            int v1 = i.next();
            if(i1[v1]==-1){
                dfs(v1,i1,a);
            }
        }
    }
    private void dfsPath(int v,int preV,int[] pre){
        pre[v] = preV;
        Iterator<Integer> i = adj(v);
        while(i.hasNext()){
            int v1 = i.next();
            if(pre[v1]==-1){
                dfsPath(v1,v,pre);
            }
        }
    }
    private void dfs(int v,int preV,boolean[] b){
        b[v] = true;
        Iterator<Integer> i = adj(v);
        while(i.hasNext()){
            int v1 = i.next();
            if(!b[v1]){
                dfs(v1,v,b);
            }
            else if(preV != v1){
                hasLoop = true;
            }
        }
    }
    private void dfs(int v,int[] a,int c,boolean[] b){
        a[v] = c;
        Iterator<Integer> i1 = adj(v);
        while(i1.hasNext()){
            int i = i1.next();
            if(a[i]==-1){
                dfs(i,a,1-c,b);
            }else if(a[i]==c){
                b[0] = false;
            }
        }
    }
    //返回图中的联通分量的个数
    public int getCount(){
        int count = 0;
        boolean[] b = new boolean[V];
        for(int i=0;i<V;i++){
            if(!b[i]){
                count++;
                dfs(i,b);
            }
        }
        return count;
    }

    //返回图中的各个联通分量
    public int[] getCC(){
        int[] b = new int[V];
        Arrays.fill(b, -1);
        for(int i=0,j=1;i<V;i++){
            if(b[i]==-1){
                dfs(i,b,j++);
            }
        }
        return b;
    }

    //查看两个点是否连通
    public boolean isConnected(int v1,int v2){
        boolean[] b1 = new boolean[V];
        dfs(v1,b1);
        return b1[v2];
    }

    //返回两个点之间的路径
    public ArrayList<Integer> Dfspath(int v,int v2){
        if(!isConnected(v,v2)){
            return new ArrayList<Integer>();
        }
        int[] pre = new int[V];
        Arrays.fill(pre, -1);
        dfsPath(v,v,pre);
        ArrayList<Integer> a = new ArrayList<>();
        int temp = v2;
        while(temp!=v){
            a.add(temp);
            temp = pre[temp];
        }
        Collections.reverse(a);
        return a;
    }

    //二分图检测
    public boolean isBinaryGraph(){
        int[] a = new int[V];
        Arrays.fill(a, -1);
        boolean[] b = new boolean[]{true};
        for(int i=0;i<V;i++){
            if(a[i]==-1){
                dfs(i,a,0,b);
            }

        }
        return b[0];
    }
    //环检测
    public boolean checkLoop(){
        boolean[] b1 = new boolean[V];
        dfs(0,0,b1);
        return hasLoop;
    }

    //bfs
    public ArrayList<Integer> bfs(int v){
        ArrayList<Integer> al = new ArrayList<>();
        boolean[] b = new boolean[V];
        Queue<Integer> q1 = new ArrayDeque<>();
        q1.add(v);
        while(!q1.isEmpty()){
            int v1 = q1.remove();
            al.add(v1);
            b[v1] = true;
            Iterator<Integer> i1 = adj(v1);
            while(i1.hasNext()){
                int v2 = i1.next();
                if(!b[v2]){
                    q1.add(v2);
                }
            }
        }
        return al;
    }

    //bfs单源路径
    public ArrayList<Integer> bfsPath(int v1,int v2){
        ArrayList<Integer> al = new ArrayList<>();
        if(!isConnected(v1,v2)){
            return al;
        }
        int[] i1 = new int[V];
        Arrays.fill(i1, -1);
        Queue<Integer> q1 = new ArrayDeque<>();
        q1.add(v1);
        i1[v1] = v1;
        while(!q1.isEmpty()){
            int v3 = q1.remove();
            Iterator<Integer> i2 = adj(v3);
            while(i2.hasNext()){
                int i3 = i2.next();
                if(i1[i3]==-1){
                    q1.add(i3);
                    i1[i3] = v3;
                }
            }
        }
        int pre = v2;
        while(pre!=v1){
            al.add(pre);
            pre = i1[pre];
        }
        al.add(v1);
        return al;
    }



    @Override
    public String toString(){
        StringBuilder sb1 = new StringBuilder();
        sb1.append(V).append("   ").append(E).append("\n");
        for(int i=0;i<V;i++){
            sb1.append(i).append(" |");
            Iterator<Integer> i1 = adj(i);
            while(i1.hasNext()){
                sb1.append(" ").append(i1.next());
            }
            sb1.append("\n");
        }
        return sb1.toString();
    }
}


class Solution {
    public boolean isBipartite(int[][] graph) {
        Graph g1 = new Graph(graph);
        return g1.isBinaryGraph();
    }
}
```