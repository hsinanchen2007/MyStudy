这是一个典型的topn问题，1000个无序的数组中取前k大个数，排序肯定是可以解决这个问题的，但是快排的时间复杂度是O(nlgn)。采用小顶堆加一次一次遍历即可。前k个元素建立小顶堆，后n - k个元素，每一个元素与小顶堆的顶部，比较，如果比小顶堆的根大，则将根元素变成该元素。由于小顶堆的删除和插入的时间复杂度是lnk，所以总计时间复杂度约为nlgk，比排序降了很多个数量级。
```
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        
        Map<String, Integer> map = new HashMap<>();
        // 第一步：计算每个重复元素的个数
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            Integer count = map.get(word);
            if (count != null) {
                count = count + 1;
                map.put(word, count);
            } else {
                map.put(word, 1);
            }
        }
        Set<Map.Entry<String, Integer>> set = map.entrySet();
        int size = set.size();
        Node[] nodes = new Node[k];
        int i = 0;
        Heap heap = null;
        // 第二步：最小堆解题
        for (Map.Entry<String, Integer> entry : set) {
            if (i < k) {
                nodes[i++] = new Node(entry.getKey(), entry.getValue());
                if (i >= size) {
                     // 构建最小堆
                    heap = new Heap(nodes);
                }
                continue;
            } else if (i == k) {
                // 构建最小堆
                heap = new Heap(nodes);
            }
            // topk
            Node first = heap.getFirstNode();
            Node newNode = new Node(entry.getKey(), entry.getValue());
            // 新的节点和小顶堆的首元素比较,替换
            if (first.compareTo(newNode) == -1) {
                // 把大的值保留下来，替换小顶堆的顶部
                heap.replace(newNode, 1, k);
            }
            i++;
        }
        // 第三步：排序输出
        List<String> list = new ArrayList<>();
        Node[] ns = heap.sort(k);
        
        for (int j = 0; j < k; j++) {
            list.add(ns[j].getValue());
        }

        return list;
    }
    

}


class Node {
    // 数量
    private int count;
    // 单词的值
    private String value;
    public Node(String value, int count) {
        this.count = count;
        this.value = value;
    }

    public int getCount() {
        return this.count;
    }

    public void setCount(int count) {
        this.count = count;
    }

    public String getValue() {
        return this.value;
    }

    public int hashCode() {
        return value.hashCode();
    }

    public boolean equals(Node node) {
        return hashCode() == node.hashCode();
    }

    public int compareTo(Node node) {
        // 堆是一个完全二叉树，右子节点可能不存在
        if (node == null) {
            return -1;
        }
        
        
        if (this.count < node.getCount()) {
            return -1;
        } else if (this.count == node.getCount()) {
            if (this.value.compareTo(node.getValue()) < 0) {
                // 数字是由大到小排序，相同的数字字符串是从小到大
                return 1;
            } else {
                return -1;
            }
        } else {
            return 1;
        }
    }
    public String toString() {
        return value + "-" + count;
    }
}

/**
*
* 堆的构建,替换
*
*/
class Heap {
    private Node[] heap;
    
    public Heap(Node[] heap) {
        this.heap = heap;
        buildHeap(heap.length / 2);
    }
    
    /**
    *最小堆的构建,重要规则
    * left = 2 * n
    * right = 2 * n + 1
    * 从最后一个非叶子节点开始，逐步向前开始构建
    * @param node 需要比对的节点，第一次是最后一个非叶子节点
    */
    public void buildHeap(int nodeOffset) {
        // 递归终止条件
        if (nodeOffset < 1) {
            return;
        }
        
        Node node = heap[nodeOffset - 1];
        
        // 左子树
        Node left = heap[nodeOffset * 2 - 1];
        Node right = null;
        if (nodeOffset * 2 + 1 <= heap.length) {
            right = heap[nodeOffset * 2];
        }
        
        // 当前节点与左子树和右子树比较，需要交换则进入判断
        if (left.compareTo(node) == -1 || (right != null && right.compareTo(node) == -1)) {
            if (left.compareTo(right) == -1) {
                // 左子树最小，和父节点进行交换
                swap(nodeOffset - 1, nodeOffset * 2 - 1);
                // 左子树的值变大，会影响该节点以下的树的顺序，需要重新调换顺序，类似插入
                replace(node, nodeOffset * 2, heap.length);
            } else {
                // 右子树最小，和父节点调换顺序
                swap(nodeOffset - 1, nodeOffset * 2 + 1 - 1);
                // 右子树的值变大，会影响该节点以下的树的顺序，需要重新调整顺序，类似插入
                replace(node, nodeOffset * 2 + 1, heap.length);
            }
        }
        
        // 该节点和左右子节点比较完毕，指针向前移动一位
        buildHeap(nodeOffset - 1);
    }
    
    public void swap(int i, int j) {
        Node temp = heap[i];
        heap[i] = heap[j];
        heap[j] = temp;
    }
    
    /**
    * 替换指定位置的元素，需要向下遍历
    * @ param node 新元素
    * @ param pos  需要替换的位置
    */
    public void replace(Node node, int pos, int endPos) {
        heap[pos - 1] = node;
        // 递归结束条件，直到该子树的叶子节点结束
        if (pos * 2 > endPos) {
            return;
        }
        
        Node left = heap[pos * 2 - 1];
        Node right = null;
        if (pos * 2 + 1 <= endPos) {
            right = heap[pos * 2];
        }

        
        if (left.compareTo(node) == -1 || (right != null && right.compareTo(node) == -1)) {
            if (left.compareTo(right) == -1) {
                // 左子树最小
                swap(pos - 1, pos * 2 - 1);
                // 左子树发生变化
                replace(node, pos * 2, endPos);
            } else {
                swap(pos - 1, pos * 2);
                // 右子树发生变化
                replace(node, pos * 2 + 1, endPos);
            }
        }

    }
    
    public Node getFirstNode() {
        return heap[0];
    }
    
    public Node getNode(int i) {
        return heap[i];
    }
    
    public void iterator() {
        for (int i = 0; i < heap.length; i++) {
            System.out.print(heap[i].toString() + ", ");
        }
        System.out.println();
    }
    
    
    /**
    * 思路：由于是小顶堆，所以，根节点是最大值，每次取出来，放到尾部，下一个最大值就又冒到顶部了，依次遍历n变即可
    * 时间复杂度：O(nlgn)
    * 空间复杂度：O(n)
    */
    public Node[] sort(int n) {
        if (n < 1) {
            return heap;
        }
        // 交换根节点和最后一个节点
        swap(0, n - 1);
        // 根节点变化了，向下遍历
        replace(heap[0], 1, --n);
        sort(n);
        return heap;
    }
}

```
