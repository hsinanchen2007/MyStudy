
```java
public static void main(String[] args) {

    // 测试用例： [2, 1, 3] 1
    
    int[] arr ={2, 1, 3};

    BST<Integer> bst = new BST<Integer>();
    for (int i = 0; i< arr.length; i++) {
        bst.add(arr[i]);
    }

    System.out.println(bst.findTarget(bst.root, 1));
}
```
代码
```java
import java.util.*;

public class BST<E> {
    protected TreeNode<E> root; // 根节点
    protected Comparator<E> comparator; // 比较器
    protected int size; // 节点个数


    public void add(E element) {
        elementNotNullCheck(element);

        if (root == null) { // 添加第一个节点

            root = new TreeNode(element);
        }else {

            TreeNode<E> node = root;
            TreeNode<E> parent;
            int cmp;

            // 获取到添加的位置
            do{
                cmp = compare(element, node.val);

                parent = node;

                if (cmp > 0) {
                    node = node.right;
                }else if (cmp < 0) {
                    node = node.left;
                }else {
                    node.val = element;
                }
            }while (node != null);

            // 在对应的位置添加节点
            TreeNode<E> newNode = new TreeNode(element);
            if (cmp > 0) {
                parent.right = newNode;
            }else if (cmp < 0) {
                parent.left = newNode;
            }
        }
        size++;
    }

    public boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;

        LinkedList<Integer> varArray = new LinkedList<Integer>();


        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();

            // 层序遍历每个元素添加到数组
            varArray.add((Integer)node.val);

            if (node.left != null) {
                queue.offer(node.left);
            }

            if (node.right != null) {
                queue.offer(node.right);
            }
        }


        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < varArray.size(); i++) {
            map.put(varArray.get(i), i);
        }

        for (int i = 0; i < varArray.size(); i++) {
            int value = k - varArray.get(i);

            if (map.containsKey(value) && map.get(value) != i) {
                return true;
            }
        }

        return false;
    }


    protected int compare(E e1, E e2) {
        if (comparator != null) {
            return comparator.compare(e1, e2);
        }
        return ((Comparable<E>) e1).compareTo(e2);
    }

    public void elementNotNullCheck(E element) {
        if (element == null) {
            throw new IllegalArgumentException("element不能为空");
        }
    }


    public class TreeNode<E> {
        E val;
        TreeNode left;
        TreeNode right;
        TreeNode(E x) { val = x; }
    }
}

```
