这是一道微软校招原题哈
用了两个小时系统的学了一下并查集
在find的时候和join的时候都进行了压缩
思路是：
0.判断connections的数量够不够连接n台机器，不够的话直接return -1;
1.把每台机器都当成一个集合，初始的时候自己是自己的father——》father[i]=i;
2.根据connections数组  把connections[i][0]和connections[i][1]进行合并，合并的时候用rank数组进行了压缩，保证高度尽可能的低;
3.根据father数组我们开始find，find的过程中进行压缩，这样把每个台机器的结果放入HashSet中去重，这样set的大小就是集合的个数了;
4.根据n个节点至少需要n-1条边连接得到答案。
```
class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length<(n-1)) return -1;
        int[] father= new int[n];
        int[] rank=new int[n];
        HashSet<Integer> set = new HashSet();
        for(int i=0;i<father.length;i++){
            father[i]=i;
            rank[i]=0;
        }

        for(int i=0;i<connections.length;i++){
            join(father,rank,connections[i][0],connections[i][1]);
        }
        for(int i=0;i<n;i++){
            set.add(find(father,i));
        }
        int union=set.size();
        //return (union-1)<(connections.length-n)?true:false;
        return union-1;


    }

    public int find(int[] father,int i){
        int son=i;
        while(father[i]!=i){
            i= father[i];
        }
        //压缩
        while(son!=i){
            int temp=father[son];
            father[son]=i;
            son=temp;
        }
        return i;
    }
    public void join(int[] father,int[] rank,int x,int y){
        int a=find(father,x);
        int b=find(father,y);
        if(a!=b){
            //压缩
            if(rank[a]>rank[b])father[b]=a;
            else if(rank[b]>rank[a])father[a]=b;
            else{
                father[a]=b;
                rank[b]++;
            }
        }
    }

}
```
