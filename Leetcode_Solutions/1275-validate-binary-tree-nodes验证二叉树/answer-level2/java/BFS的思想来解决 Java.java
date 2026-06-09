```
class Solution {
    boolean[] visited;
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        visited=new boolean[n];
        visited[0]=true;
        LinkedList<Integer> list=new LinkedList<>();
        list.add(0);
        while(!list.isEmpty()){
            int size=list.size();
            while(size-->0){
                int t=list.pollFirst();
                
                if(leftChild[t]!=-1){
                    if(visited[leftChild[t]]) return false;  //如果曾经被访问，那么说明这个点有不止一个入度
                    list.add(leftChild[t]);
                    visited[leftChild[t]]=true;
                }
                if(rightChild[t]!=-1){
                    if(visited[rightChild[t]]) return false;  
                    list.add(rightChild[t]);
                    visited[rightChild[t]]=true;
                } 
            }
        }

        //如果某个节点没被访问过，说明上面的BFS图没有联通，就是case 4的情况，那么也是return false；
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }
        return true;
    }
}
```
看到一个老哥用计算图的入度算的，那个更加高效[https://leetcode-cn.com/problems/validate-binary-tree-nodes/solution/ji-suan-tu-de-ru-du-by-codehuman/]()
