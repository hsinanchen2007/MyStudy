**方法一 前序遍历+排序**
1. 先将两棵树的所有节点都放到一个$list$中，这里可以采用各种类型的遍历（前序、中序、后序、层次）；
2. 然后将$list$进行排序即可。

```java
public class Problem02 {

    private List<Integer> ansList;

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }

        ansList.add(root.val);
        dfs(root.left);
        dfs(root.right);
    }

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        ansList = new ArrayList<>();
        dfs(root1);
        dfs(root2);
        Collections.sort(ansList);
        return ansList;
    }

}

```
**复杂度分析**
时间复杂度：$O(nlogn)$。因为用到了排序。
空间复杂度：$O(n)$。开辟了一个$m+n$(跟$n$同量级)大小的$list$，$m$代表$tree1$的节点数、$n$代表$tree2$的节点数。

**方法二 分别中序遍历+归并**
前提：这两棵树都是二叉搜索树$（BST）$，而一颗$BST$中序遍历的结果就是排好序的。
1. 新建两个$list$，分别对两棵树进行中序遍历得到分别排好序的$list1，list2$;
2. 已知$list1$和$list2$有序，那么将二者归并即可的到一个排好序的总$list$。（这里时间复杂度也就$O(n)$）。

```java
public class Problem02_1 {

    private void dfs(TreeNode root, List<Integer> ansList) {
        if (root == null) {
            return;
        }

        dfs(root.left, ansList);
        ansList.add(root.val);
        dfs(root.right, ansList);
    }

    private List<Integer> merge(List<Integer> list1, List<Integer> list2) {
        List<Integer> ansList = new ArrayList<>();
        int size1 = list1.size();
        int size2 = list2.size();
        int index1, index2;
        for (index1 = 0, index2 = 0; index1 < size1 && index2 < size2;) {
            int num1 = list1.get(index1);
            int num2 = list2.get(index2);
            if (num1 < num2) {
                ansList.add(num1);
                index1++;
            } else {
                ansList.add(num2);
                index2++;
            }
        }

        while (index1 < size1) {
            ansList.add(list1.get(index1++));
        }

        while (index2 < size2) {
            ansList.add(list2.get(index2++));
        }

        return ansList;
    }

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        List<Integer> ansList1 = new ArrayList<>();
        List<Integer> ansList2 = new ArrayList<>();
        dfs(root1, ansList1);
        dfs(root2, ansList2);

        return merge(ansList1, ansList2);
    }

}
```
**复杂度分析**
时间复杂度：$O(n)$. 两次的中序遍历和一次的归并操作都是$O(n)$的时间复杂度。
空间复杂度：$O(n)$.

**方法三 遍历+优先队列**
1. 在树遍历的时候用一个优先队列（默认小根堆）来添加元素；
2. 然后，将优先队列的元素逐个取出到$list$中即可。

```java
public class Problem02_2 {

    private PriorityQueue<Integer> priorityQueue;

    private void dfs(TreeNode root) {
        if (root == null) {
            return;
        }

        priorityQueue.offer(root.val);
        dfs(root.left);
        dfs(root.right);
    }

    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        priorityQueue = new PriorityQueue<>();
        dfs(root1);
        dfs(root2);
        List<Integer> ansList = new ArrayList<>();
        while (!priorityQueue.isEmpty()) {
            ansList.add(priorityQueue.poll());
        }
        return ansList;
    }

}
```
**复杂度分析**
时间复杂度：$O(nlogn)$。因为优先队列插入和删除的操作的时间复杂度都是$O(logn)$，然后有$n$节点，就是$O(nlogn)$.
空间复杂度：$O(n)$