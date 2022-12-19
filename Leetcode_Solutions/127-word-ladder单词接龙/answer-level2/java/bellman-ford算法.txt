### 解题思路
bellman-ford算法

### 代码

```java
class Solution {
public static void main(String[] args) {
        Solution solution = new Solution();
        String beginWord="hit";
        String endWord="cog";
        List<String> wordList= new ArrayList<>(Arrays.asList(new String[]{"hot", "dot", "dog", "lot", "log", "cog"}));
        int res=solution.ladderLength(beginWord,endWord,wordList);
        System.out.println("res = " + res);
    }
    /**
     * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
     * <p>
     * 每次转换只能改变一个字母。
     * 转换过程中的中间单词必须是字典中的单词。
     * 输入:
     * beginWord = "hit",
     * endWord = "cog",
     * wordList = ["hot","dot","dog","lot","log","cog"]
     * <p>
     * 输出: 5
     * <p>
     * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     * 返回它的长度 5。
     *
     * @param beginWord
     * @param endWord
     * @param wordList
     * @return
     */
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        /**
         * 感谢 bellman-ford算法, 这类最短距离我打算采用这个算法
         * wordList 的长度+beginWord为vertex, 然后搞一个类来记录路径,包含from, to, weight.
         * dis数组来记录从开始到后面的距离.初始化为999.(因为权值都为1)
         */
 //处理特殊情况,beginWord 在wordList里面
        boolean isContain=false;
        if (wordList.contains(beginWord)) isContain=true;
        if (!wordList.contains(endWord)) return 0;

        //开始生成图
        int vertex = isContain?wordList.size():wordList.size() + 1;
        
        int target=0;
        ArrayList<String> list = new ArrayList<>(wordList);
        list.remove(beginWord);
        String[] vertexArray = new String[vertex];
        vertexArray[0]=beginWord;
        for (int i = 0; i < list.size(); i++) {
            vertexArray[i+1]=list.get(i);
            if (list.get(i).equals(endWord)){
                target=i+1;
                // System.out.println("target = " + target);
            }
        }
//        for (String s : vertexArray) {
//            System.out.println("s = " + s);
//        }
        int[] dis=new int[vertex];
        int [] preNode=new int[vertex];

        for (int i = 1; i < dis.length; i++) {
            dis[i]=999;//init
        }
        ArrayList<Edge> edgeList = new ArrayList<>();
        // 构建边
        for (int i = 0; i < vertexArray.length; i++) {
            String from = vertexArray[i];
            for (int j = 0; j < vertexArray.length; j++) {
                String to = vertexArray[j];
                if (canReach(from, to)) {
                    edgeList.add(new Edge(from, to, i, j));
                }
            }
        }

        // 开始按照bellman-ford 算法计算
        for (int i = 0; i < vertex; i++) {
            for (int j = 0; j < edgeList.size(); j++) {
                Edge edge = edgeList.get(j);
                int fromVertex=edge.fromIndex;
                int toVertex=edge.toIndex;
                if (dis[fromVertex]+1<dis[toVertex]){
                    dis[toVertex]=dis[fromVertex]+1;
                    preNode[toVertex]=fromVertex;
                }
            }
        }
        // for (int i = 0; i < vertex; i++) {
        //     showPath(preNode,0,i,vertexArray);
        //     System.out.println("-------"+vertexArray[0]+"到" + vertexArray[i] + "的距离：" + dis[i]);
        // }
        return dis[target]==999?0:dis[target]+1;
    }

    private void showPath(int[] path, int from, int to, String[] vertexArray) {
        int pre;
        if (from == to) {
            System.out.print(vertexArray[to] + " ");
            return;
        }
        pre = path[to];
        showPath(path, from, pre, vertexArray);
        System.out.print(" " + vertexArray[to] + " ");
    }


    private boolean canReach(String from, String to) {
        int i = 0;
        int count = 0;

        while (i < from.length()) {
            if (from.charAt(i) != to.charAt(i)) {
                count++;
            }
            i++;
        }
        return count == 1;
    }

    public class Edge {
        public String from;
        public String to;
        public int fromIndex;
        public int toIndex;
        public int weight = 1;

        public Edge(String from, String to, int fromIndex, int toIndex) {
            this.from = from;
            this.to = to;
            this.fromIndex = fromIndex;
            this.toIndex = toIndex;
        }
    }
}
```