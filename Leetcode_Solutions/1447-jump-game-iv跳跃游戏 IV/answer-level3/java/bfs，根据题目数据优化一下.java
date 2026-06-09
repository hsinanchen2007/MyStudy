### 解题思路
直接用bfs超时了，后面有一个数据是一串很长7连着什么的
所以对连在一起的相同数据进行合并一下，生成一个新数组

### 代码

```java
import java.util.*;
class Solution {
    public static int minJumps(int[] arr) {

        //对连在一起的相同数据进行合并 生成新数组
        List<Integer> list = new ArrayList<>();
        list.add(arr[0]);
        int count = 0;
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] - arr[i - 1] == 0) {
                count++;
                if (count == 2) 
                    list.add(arr[i]);
            } else {
                count = 0;
                list.add(arr[i]);
            }
        }
        arr = new int[list.size()];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = list.get(i);
        }
        //--------------------------------------

        //对每个元素值生成他的所有索引位置 方便之后查询，不然每次到一个元素都要循环一遍数组找和他相同的值
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < arr.length; i++) {
            List<Integer> l = map.getOrDefault(arr[i], new ArrayList<>());
            l.add(i);
            map.put(arr[i], l);
        }

        //标准的BFS
        HashSet<Integer> visited = new HashSet<>();
        Queue<JumpNode> queue = new LinkedList<>();
        queue.offer(new JumpNode(arr[0], 0, 0));
        visited.add(0);
        while (!queue.isEmpty()) {
            JumpNode node = queue.poll();
            if (node.index == arr.length - 1)
                return node.cost;
            else
                queue.addAll(expand(node, visited, arr, map));
        }
        return -1;
    }

    private static List<JumpNode> expand(JumpNode node, HashSet<Integer> visited, int[] arr, HashMap<Integer, List<Integer>> map) {
        List<JumpNode> list = new ArrayList<>();
        //试图扩展到左边的节点
        if (node.index - 1 >= 0 && !visited.contains(node.index - 1)) {
            list.add(new JumpNode(arr[node.index - 1], node.index - 1, node.cost + 1));
        }
        //试图扩展到右边的节点
        if (node.index + 1 < arr.length && !visited.contains(node.index + 1)) {
            list.add(new JumpNode(arr[node.index + 1], node.index + 1, node.cost + 1));
        }
         //试图扩展到相同值的其他元素
        List<Integer> sameValueIndex = map.get(node.value);
        sameValueIndex.forEach(i -> {
            if (!visited.contains(i))
                list.add(new JumpNode(node.value, i, node.cost + 1));
        });

        list.forEach(i -> {
            visited.add(i.index);
        });
        return list;
    }
}

class JumpNode {
    public int index;
    public int value;
    public int cost;

    public JumpNode(int value, int index, int cost) {
        this.value = value;
        this.index = index;
        this.cost = cost;
    }
}
```