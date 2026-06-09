 ###  102. 二叉树的层次遍历 Medium
```
public List<List<Integer>> levelOrder(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    if (root == null) return result;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.offer(root);
    int level = 0;
    while (!queue.isEmpty()) {
        result.add(new ArrayList<>());
        int size = queue.size();
        for (int i = 0; i < size; i++) {
            TreeNode cur = queue.poll();
            result.get(level).add(cur.val);
            if (cur.left != null) queue.add(cur.left);
            if (cur.right != null) queue.add(cur.right);
        }
        ++level;
    }
    return result;
}
```


### 举一反三：二叉树按层打印，左神P130
```
public void printByLevel(TreeNode head) {
    if (head == null) return;
    Queue<TreeNode> queue = new LinkedList<>();
    int level = 0;
    TreeNode last = head;
    TreeNode nLast = null;
    queue.offer(last);
    System.out.print("Level " + (level++) + " : ");
    while (!queue.isEmpty()) {
        TreeNode cur = queue.poll();
        System.out.print(cur.val + " ");
        if (cur.left != null) {
            queue.offer(cur.left);
            nLast = cur.left;
        }
        if (cur.right != null) {
            queue.offer(cur.right);
            nLast = cur.right;
        }
        if (cur == last && !queue.isEmpty()) {
            System.out.print("\nLevel" + (level++) + " : ");
            last = nLast;
        }
    }
}
```


### 103. 二叉树的锯齿形层次遍历 Medium
### 方法1：奇偶栈
```
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;
        //odd 奇栈，even 偶栈，FILO
        // 第一层，第二层为从左到右，stackOdd先加right元素，再加left元素
        //第二层，第四为从右到左，stackEven先加left元素，再加right元素
        Stack<TreeNode> stackOdd = new Stack<>();
        Stack<TreeNode> stackEven = new Stack<>();
        stackOdd.add(root);
        List<Integer> levelList = null;
        while (!stackOdd.isEmpty() || !stackEven.isEmpty()) {
            levelList = new ArrayList<>();
            if (!stackOdd.isEmpty()) {
                while (!stackOdd.isEmpty()) {
                    TreeNode odd = stackOdd.pop();
                    levelList.add(odd.val);
                    if (odd.left != null) stackEven.push(odd.left);
                    if (odd.right != null) stackEven.push(odd.right);
                }
            } else {
                while (!stackEven.isEmpty()) {
                    TreeNode even = stackEven.pop();
                    levelList.add(even.val);
                    if (even.right!=null) stackOdd.push(even.right);
                    if (even.left!=null) stackOdd.push(even.left);
                }
            }
            result.add(levelList);
        }
        return result;
    }
```



### 方法2：DFS
```
public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
    List<List<Integer>> result = new ArrayList<>();
    if (root == null) return result;
    Queue<TreeNode> queue = new LinkedList<>();
    queue.add(root);
    int level = 0;
    while (!queue.isEmpty()) {
        List<Integer> levelList = new ArrayList<>();
        int size = queue.size();//一次性倒出queue的一层元素
        for (int i = 0; i < size; i++) {
            TreeNode cur = queue.poll();
            //level记录层数，按奇偶行来添加元素，add(0, cur.val)表示新进来的元素都放在头部
            if (level % 2 == 0) levelList.add(cur.val);
            else levelList.add(0, cur.val);
            if (cur.left != null) queue.offer(cur.left);
            if (cur.right != null) queue.offer(cur.right);
        }
        level++;
        result.add(levelList);
    }
    return result;
}
```

### 总结
- 按Zig打印的两个关键点：
    - 判断奇偶数行，可以通过`level`计数，可以通过奇偶栈，可以通过一些`flag`标志，不断反转
    - 使用容器或是在塞进list时，相邻行需要错开顺序，可以通过`Deque`的方式，可以通过 `levelList.add(0, cur.val)`，可以通过`LinkedList`的`addFirst`
