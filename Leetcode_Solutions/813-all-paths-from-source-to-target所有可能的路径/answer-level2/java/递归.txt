class Solution {

    List<List<Integer>> allPath = new ArrayList<List<Integer>>();//所有路径

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<Integer> path = new ArrayList<Integer>();//一条空路径
        paths(graph,path,0);//从第0个位置开始
        return allPath;
    }

    public void paths(int[][] graph, List<Integer> path, int index){//path:当前路径,index:当前位置
        path.add(index);
        if(index == graph.length-1){//若为最后一个节点返回一整条路径
            allPath.add(path);//一条完整的路径
        }else{
            for(int i = 0; i < graph[index].length; i++){
                if(i != graph[index].length-1){//若不为当前节点最后一条路径
                    //复制当前已有路径（不会更改当前位置路径）
                    paths(graph,new ArrayList<Integer>(path),graph[index][i]);
                }else{
                    paths(graph,path,graph[index][i]);
                }
            }
        }
    }
}

![1.png](https://pic.leetcode-cn.com/439fa281bdf76a053f97421e950dbc35ad3c72eedfd7ec028e4bec012240f12c-1.png)

如果帮到你了请夸我哈哈哈