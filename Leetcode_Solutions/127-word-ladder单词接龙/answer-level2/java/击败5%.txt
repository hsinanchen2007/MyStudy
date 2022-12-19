### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if(!wordList.contains(endWord)){
            return 0;
        }
        if(beginWord.equals(endWord)){
            return 1;
        }
        int len = wordList.size();
        // 这是一个无向图的问题，从起点到终点，所有边的权值都为1
        int target = findTarget(wordList, endWord);
        // 把起点也要加进去图里去,起点放在最后
        wordList.add(beginWord);
        Map<Integer, List<Integer>> graph = GenerateGraph(wordList);
        // 声明一个布尔值的数组用来记录节点是否经过
        boolean[] visited = new boolean[len + 1];
        int ret = 0;
        // 按广度搜索
        Queue<Integer> queue = new LinkedList<>();
        queue.offer(len);
        visited[len] = true;
        while(!queue.isEmpty()){
            ret++;
            int size = queue.size();
            while(size-- > 0){
                int node = queue.poll();
                // 找到node相邻的点
                for(int n : graph.get(node)){
                    if(n == target){
                        return ret + 1;
                    }
                    if(visited[n] == false){
                        visited[n] = true;
                        queue.offer(n);
                    }
                }
            }
        }
        return 0;



        
    }
    
    // 生成图
    private Map<Integer, List<Integer>> GenerateGraph(List<String> wordList){
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for(int i = 0; i < wordList.size(); i++){
            List<Integer> list = new ArrayList<>();
            for(int j = 0; j < wordList.size(); j++){       
                if(i != j && isConnected(wordList.get(i), wordList.get(j))){
                    list.add(j);
                }
            }
            graph.put(i, list);
        }
        return graph;
    }

    // 找到endWord所在的位置
    private int findTarget(List<String> wordList, String target){
        for(int i = 0; i < wordList.size(); i++){
            if(wordList.get(i).equals(target)){
                return i;
            }
        }
        return -1;
    }
    // 两个字符串如果只有一个字母不同，则可以认为是相连的点
    private boolean isConnected(String s1, String s2){
        int life = 1;
        for(int i = 0; i < s1.length(); i++){
            if(s1.charAt(i) != s2.charAt(i)){
                life--;
                if(life < 0){
                    return false;
                }
            }
        }
        return true;
    }

}
```