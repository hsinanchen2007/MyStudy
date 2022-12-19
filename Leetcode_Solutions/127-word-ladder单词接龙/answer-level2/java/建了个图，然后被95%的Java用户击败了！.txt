### 解题思路
我想到的是自己建个图，本以为可以击败95%的同学，没想到被95%的同学击败了，有点搞幽啊！

### 代码

```java
class Solution {
     public static int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // 字典为空，当然返回 0
        if(wordList == null){
            return 0;
        }

        // 查找 endWord 在链表的哪个位置，下标从 1 开始
        int endIndex = 0;
        int length = wordList.size();
        Iterator<String> iteratorStr = wordList.iterator();
        Iterator<Integer> iteratorInt;
        for(int i = 1; i <= length; i++){
            if(endWord.equals(iteratorStr.next())){
                endIndex = i;
                break;
            }
        }

        // 字典中没有 endWord, 返回 0
        if(endIndex == 0)
            return 0;

        // 我的图是一个装着链表的数组，因为节点个数是固定的
        LinkedList<Integer>[] adjList = buildGraph(beginWord, wordList);
        // 用来放带检索的节点的
        Queue<Integer> queue = new LinkedList<>();
        // 每一个字符串都可以对应一个整数，字典里的按链表序列 + 1, beginWord 设为 0 , 故可以用Map<Integer, Integer>
        // value 的值为到 beginWord 的距离
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, 0);
        for(int i = 1; i <= length; i++){
            // 初始化为最大值
            map.put(i, Integer.MAX_VALUE);
        }

        queue.add(0);
        while(!queue.isEmpty()){
            Integer prev = queue.remove();
            // 需要考虑该节点为孤立节点的情况，即字典里没有与 beginWord 只相差一个字符的
            if(adjList[prev] == null)
                continue;
            // 用iterator提高检索效率
            iteratorInt = adjList[prev].iterator();
            while(iteratorInt.hasNext()){
                Integer next = iteratorInt.next();
                int prevVal = map.get(prev);
                // 如果该节点连着endWord, 则必须进行比较后，更新小值
                if(next == endIndex && map.get(endIndex) > prevVal + 1){
                    map.put(next, prevVal + 1);
                }
                // 如果连着该节点的节点的value > prevVal + 1, 说明之前没有检索过，或者检索过，但是那条路子的距离有点远，故而需要更新，并且加入队列 
                if(map.get(next) > prevVal + 1){
                    map.put(next, prevVal + 1);
                    queue.add(next);
                }
            }
        }
        
        
        int ladderLength = map.get(endIndex);
        // 检查 endWord 到 beginWord 的距离是否被动过，没被动过返回 0
        if(ladderLength == Integer.MAX_VALUE)
             return 0;
        else
             return ladderLength + 1;
    }

    // 以下是建立图的连接关系，常规
    public static LinkedList<Integer>[] buildGraph(String beginWord, List<String> wordList){
        int length = 1 + wordList.size();
        LinkedList<Integer>[] adjList = new LinkedList[length];
        LinkedList<Integer> subList = new LinkedList<>();
        Iterator<String> iterator = wordList.iterator();
        for(int i = 1; i <= length - 1; i++){
            if(diffOne(beginWord, iterator.next())){
                subList.add(i);
            }
        }
        adjList[0] = subList;

        for(int i = 1; i <= length - 1; i++){
            subList = new LinkedList<>();
            String word = wordList.get(i - 1);
            if(diffOne(beginWord, word)){
                subList.add(0);
            }
            iterator = wordList.iterator();
            for(int j = 1; j <= length - 1; j++){
                if(diffOne(word, iterator.next())){
                    subList.add(j);
                }
            }
            // 注意为空的情况
            if(subList.size() == 0){
                adjList[i] = null;
            }
            else{
                adjList[i] = subList;
            }
        }
        return adjList;
    }

    public static boolean diffOne(String str1, String str2){
        int length = str1.length();
        if(length != str2.length())
            return false;

        int diff = 0;
        for(int i = 0; i < length; i++){
            if(str1.charAt(i) != str2.charAt(i))
                diff++;
        }
        return diff == 1;
    }
}
```