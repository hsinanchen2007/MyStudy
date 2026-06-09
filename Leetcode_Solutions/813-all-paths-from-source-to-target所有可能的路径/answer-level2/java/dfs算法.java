```
class Solution {
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        //图中节点个数
        int nodenums = graph.length;
        //单次路径
        List<Integer> list = new LinkedList<>();
        list.add(0);
        //结果集
        List<List<Integer>> result = new LinkedList<>();
        //dfs深度优先搜索
        findPath(graph,0,list,result);
        return result;
    }

    public static void  findPath(int[][] g,int x,List<Integer> list,List<List<Integer>> result){
        if(x==g.length-1){
            //这里需要new一个新的list，因为如果不new新的，直接存进去，在后面循环的时候，进入第二条路径，又会在对list进行操作，第一个路径就被改变了
            result.add(new LinkedList(list));
            return;
        }
        for(int i = 0;i<g[x].length;i++){
            list.add(g[x][i]);
            //这里重新注入的位置，应该是当前list添加的数，因为这个数就代表着到达的下一个节点
            findPath(g,g[x][i],list,result);
            //因为在findPath递归的时候，最底层的时候，就是前面的条件判断，结果集里已经加入了new的list，所以当前list的内容需要删除，因为是递归，所以需要删除每次从底层递归添加的最后一个数
            list.remove(list.size()-1);
        }
    }
}
```
