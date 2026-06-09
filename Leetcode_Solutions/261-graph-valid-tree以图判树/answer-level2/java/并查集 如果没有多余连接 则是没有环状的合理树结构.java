```
class Solution {
    public boolean validTree(int n, int[][] edges) {
        int[] rank=new int[n];
        for (int i=0;i<rank.length;i++){
            rank[i]=i;
        }

        for (int i=0 ;i <edges.length ;i++){
            if (find(rank,edges[i][0])==find(rank,edges[i][1])){
                return false;
            }
            union(rank,edges[i][0],edges[i][1]);
        }

        for (int i=0;i<rank.length;i++){
            if (find(rank,i)!=0){
                return false;
            }
        }
        return true;
    }

    public int find(int[] rank, int index){
        if (rank[index]==index){
            return rank[index];
        }
        return rank[index]=find(rank,rank[index]);
    }

    public void union(int[] rank, int index1, int index2){
        if (rank[index1]<rank[index2]){
            rank[rank[index2]]=rank[rank[index1]];
        }
        else{
            rank[rank[index1]]=rank[rank[index2]];
        }
    }
}
```
