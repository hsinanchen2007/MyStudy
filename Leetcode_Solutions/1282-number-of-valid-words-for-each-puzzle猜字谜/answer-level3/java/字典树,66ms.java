## 思路
1. 通过字典树保存所有的word
2. 通过递归查找符合条件的word

## 重要操作
### 1. 需要将word和puzzle规则化，方便储存和查询
1. 去重
2. 排序
3. 将char变成int

例如：baacc变成012，dac变成023


### 2. 在字典树节点中保存节点的路径，用于判断该节点是否保存puzzle的第一个字符



## 代码
```
class Solution {
    /**
     * 将所有的word保存成类似字典树一样的结构
     */
    private static class Node {
        private Node[] children = new Node[26];   // 子节点
        private int count = 0;                    // 当前节点word的个数
        private boolean[] path = new boolean[26]; // 从根节点到当前节点的路径，路径中存在的字符为true
        
        public Node getChild(int idx) {
            Node child = children[idx];
            if (child == null) {
                child = children[idx] = createChild(idx);
            }
            return child;
        }
        
        private Node createChild(int idx) {
            Node child = new Node();
            boolean[] childPath = Arrays.copyOf(path, 26);
            childPath[idx] = true;
            child.path = childPath;
            return child;
        }
        
        public Node getChildNotCreate(int idx) {
            return children[idx];
        }
        
        public int getCount(int idx) {
            return path[idx] ? count : 0;
        }
        
        
        public void addCount() {
            count++;
        }
    }
    public List<Integer> findNumOfValidWords(String[] words, String[] puzzles) {
        Node root = new Node();
        
        for (String word : words) {
            int[] normal = normal(word); // 将word规则化
            put(root, normal); // 添加到树中
        }
        
        List<Integer> res = new ArrayList<>();
        
        for (String puzzle : puzzles) {
            int first = puzzle.charAt(0) - 'a'; // 保存第一个字符
            int[] normal = normal(puzzle); // 将puzzle规则化
            res.add(get(root, normal, first)); // 查询放到结果中
        }
        
        return res;
    }
    
    /**
     * 将字符串规则化，为了方便储存和查找
     * 1. 去重
     * 2. 排序
     * 3. 将char变成int
     */
    private static int[] normal(String str) {
        boolean[] exists = new boolean[26];
        int len = str.length();
        int size = 0;
        
        for (int i = 0; i < len; i++) {
            int idx = str.charAt(i) - 'a';
            if (!exists[idx]) {
                exists[idx] = true;
                size++;
            }
        }
        
        int[] res = new int[size];
        int k = 0;
        for (int i = 0; i < 26; i++) {
            if (exists[i]) {
                res[k++] = i;
            }
        }
        
        return res;
    }
    
    
    /**
     * 将word放入树中
     */
    private static void put(Node root, int[] data) {
        if (data.length > 7) { // 长度大于7肯定无效
            return;
        }
        
        Node cur = root;
        for (int idx : data) {
            cur = cur.getChild(idx);
        }
        
        cur.addCount();
    }
    
    /**
     * 在数中查找符合条件的word个数
     */
    private static int get(Node root, int[] data, int first) {
        int cnt = 0;
        for (int i = 0; i < data.length; i++) {
            cnt += get(root, data, i, first);
        }
        return cnt;
    }
    
    /**
     * 递归查找
     */
    private static int get(Node node, int[] data, int s, int first) {
        int len = data.length;
        if (len == s) {
            return node.getCount(first);
        }
        
        int cnt = 0;
        Node cur = node.getChildNotCreate(data[s]);
        if (cur != null) {
            for (int i = s + 1; i <= len; i++) {
                cnt += get(cur, data, i, first);
            }
        }
        return cnt;
    }
}
```

