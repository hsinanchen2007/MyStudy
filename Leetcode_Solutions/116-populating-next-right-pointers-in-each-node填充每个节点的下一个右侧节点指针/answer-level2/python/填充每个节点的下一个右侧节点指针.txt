#### 方法一：层序遍历

**思路**

树和图的两种基本遍历方法。一种是深度优先方法，例如：每次只遍历一个分支；另外一种是广度优先方法，例如：先遍历完这一层再进入下一层。树的深度优先遍历又可以分为先序遍历 `preorder`、中序遍历 `inorder` 和后序遍历 `postorder`。树的广度优先遍历基于节点的层级 `level` 概念。一个节点的层级取决于该节点的深度或者到根节点的距离。需要先遍历完同一层级的所有节点，才能进入下一层级。

![](https://pic.leetcode-cn.com/Figures/116/img1.png){:width=480}

很明显，此问题应该使用广度优先遍历解决。使用广度优先遍历，可以将同一层级的所有节点连接起来。

**算法**

1. 创建一个辅助队列 `Q`，可以通过多种方式实现层序遍历，尤其是在在识别特定节点的时候。

    1. 在队列中以 $(node, level)$ 的形式存储节点，同时存储其子节点为 $\text (node.left, \;\; parent\_level + 1)$ 和 $(node.right,\;\; parent\_level + 1)$。这种方法节点多了一个层级属性，需要创建一个新的数据结构，效率很低。    
       
    ![](https://pic.leetcode-cn.com/Figures/116/img2.png){:width=480}

    2. 可以使用一个标记分离不同层级之间的节点。通常情况下，在队列中插入一个 `NULL` 元素，标记当前层级结束，下一层级开始。但是这种方法会创建与层级数量相同个数的 `NULL` 元素，造成过多内存消耗。

        ![](https://pic.leetcode-cn.com/Figures/116/img3.png){:width=480}

    3. 该方法使用嵌套循环结构，避免了方法二中的 `NULL` 元素。该方法的每一步都需要记录当前队列中 ***全部*** 元素数量，对应树中一个层级元素的数量。然后从队列中处理对应数量的元素。完成后，这一层级所有的节点都被访问，队列包含下一层级的 ***全部*** 节点。下面是对应伪代码：

        ```python [snippet1-Python]
        while (!Q.empty())
        {
            size = Q.size()
            for i in range 0..size
            {
                node = Q.pop()
                Q.push(node.left)
                Q.push(node.right)
            }
        }
        ```

2. 首先在队列中加入根节点。因为第 0 层级只有一个节点，不需要建立连接，直接进入 `while` 循环即可。

    ![](https://pic.leetcode-cn.com/Figures/116/img4.png){:width=480}

3. 伪代码中 `while` 循环迭代的是树的层级，内部的 `for` 循环迭代的是一个层级上所有的节点。由于可以访问同一层级的所有节点，因此能够建立指针连接。

4. `for` 循环弹出一个节点时，同时把它的孩子节点加入队列。因此队列中每个层级的元素也是顺序存储的。可以通过已有的顺序建立 `next` 指针。

    ![](https://pic.leetcode-cn.com/Figures/116/img5.png){:width=480}

```java [solution1-Java]
class Solution {
    public Node connect(Node root) {
        
        if (root == null) {
            return root;
        }
        
        // Initialize a queue data structure which contains
        // just the root of the tree
        Queue<Node> Q = new LinkedList<Node>(); 
        Q.add(root);
        
        // Outer while loop which iterates over 
        // each level
        while (Q.size() > 0) {
            
            // Note the size of the queue
            int size = Q.size();
            
            // Iterate over all the nodes on the current level
            for(int i = 0; i < size; i++) {
                
                // Pop a node from the front of the queue
                Node node = Q.poll();
                
                // This check is important. We don't want to
                // establish any wrong connections. The queue will
                // contain nodes from 2 levels at most at any
                // point in time. This check ensures we only 
                // don't establish next pointers beyond the end
                // of a level
                if (i < size - 1) {
                    node.next = Q.peek();
                }
                
                // Add the children, if any, to the back of
                // the queue
                if (node.left != null) {
                    Q.add(node.left);
                }
                if (node.right != null) {
                    Q.add(node.right);
                }
            }
        }
        
        // Since the tree has now been modified, return the root node
        return root;
    }
}
```

```python [solution1-Python]
import collections 

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        # Initialize a queue data structure which contains
        # just the root of the tree
        Q = collections.deque([root])
        
        # Outer while loop which iterates over 
        # each level
        while Q:
            
            # Note the size of the queue
            size = len(Q)
            
            # Iterate over all the nodes on the current level
            for i in range(size):
                
                # Pop a node from the front of the queue
                node = Q.popleft()
                
                # This check is important. We don't want to
                # establish any wrong connections. The queue will
                # contain nodes from 2 levels at most at any
                # point in time. This check ensures we only 
                # don't establish next pointers beyond the end
                # of a level
                if i < size - 1:
                    node.next = Q[0]
                
                # Add the children, if any, to the back of
                # the queue
                if node.left:
                    Q.append(node.left)
                if node.right:
                    Q.append(node.right)
        
        # Since the tree has now been modified, return the root node
        return root
```

**复杂度分析**

* 时间复杂度：$O(N)$。每个节点被访问一次，即从队列中弹出，并建立 `next` 指针。

* 空间复杂度：$O(N)$。这是一棵完美二叉树，它的最后一个层级包含 $N/2$ 个节点。广度优先遍历的复杂度取决于一个层级上的最大元素数量。这种情况下空间复杂度为 $O(N)$。


#### 方法二：使用已建立的 `next` 指针

**思路**

一棵树中，存在两种类型的 `next` 指针。

1. 第一种情况是连接同一个父节点的两个子节点。它们可以通过同一个节点直接访问到，因此执行下面操作即可完成连接。

    ```java [snippet1-Java]
    node.left.next = node.right
    ```

    ![](https://pic.leetcode-cn.com/Figures/116/img6.png){:width=480}

2. 第二种情况在不同父亲的子节点之间建立连接，这种情况不能直接连接。

    ![](https://pic.leetcode-cn.com/Figures/116/img7.png){:width=480}

    如果每个节点有指向父节点的指针，可以通过该指针找到 `next` 节点。如果不存在该指针，则按照下面思路建立连接：

> 第 N 层节点之间建立 `next` 指针后，再建立第 N+1 层节点的 `next` 指针。可以通过 `next` 指针访问同一层的所有节点，因此可以使用第 N 层的 `next` 指针，为第 N+1 层节点建立 `next` 指针。

**算法**

1. 从根节点开始，由于第 0 层只有这一个节点，所以不需要连接。直接为第 1 层节点建立 `next` 指针即可。该算法中需要注意的一点是，当我们为第 N 层节点建立 `next` 指针时，处于第 $N-1$ 层。当第 $N$ 层节点的 `next` 指针全部建立完成后，移至第 $N$ 层，建立第 $N+1$ 层节点的 `next` 指针。

2. 遍历某一层的节点时，这层节点的 `next` 指针已经建立。因此我们只需要知道这一层的最左节点，就可以按照链表方式遍历，不需要使用队列。

3. 上面思路的伪代码如下：

    ```java [snippet2-Java]
    leftmost = root
    while (leftmost.left != null)
    {
        head = leftmost
        while (head.next != null)
        {
            1) Establish Connection 1
            2) Establish Connection 2 using next pointers
            head = head.next
        }
        leftmost = leftmost.left
    }
   ```

    ![](https://pic.leetcode-cn.com/Figures/116/img8.png){:width=480}


4. 两种类型的 `next` 指针，
   
    1. 第一种情况两个子节点属于同一个父节点，因此直接通过父节点建立两个子节点的 `next` 指针即可。

        ```java [snippet3-Java]
        node.left.next = node.right
        ```

    ![](https://pic.leetcode-cn.com/Figures/116/img9.png){:width=480}


   2. 第二种情况是连接不同父节点之间子节点的情况。更具体地说，连接的是第一个父节点的右孩子和第二父节点的左孩子。由于已经在父节点这一层建立了 `next` 指针，因此可以直接通过第一个父节点的 `next` 指针找到第二个父节点，然后在它们的孩子之间建立连接。

        ```java [snippet4-Java]
        node.right.next = node.next.left
        ```   
        
    ![](https://pic.leetcode-cn.com/Figures/116/img10.png){:width=480}
        
5. 完成当前层的连接后，进入下一层重复操作，直到所有的节点全部连接。进入下一层后需要更新最左节点，然后从新的最左节点开始遍历该层所有节点。因为是完美二叉树，因此最左节点一定是当前层最左节点的左孩子。如果当前最左节点的左孩子不存在，说明已经到达该树的最后一层，完成了所有节点的连接。

    ![](https://pic.leetcode-cn.com/Figures/116/img11.png){:width=480}

```java [solution2-Java]
class Solution {
    public Node connect(Node root) {
        
        if (root == null) {
            return root;
        }
        
        // Start with the root node. There are no next pointers
        // that need to be set up on the first level
        Node leftmost = root;
        
        // Once we reach the final level, we are done
        while (leftmost.left != null) {
            
            // Iterate the "linked list" starting from the head
            // node and using the next pointers, establish the 
            // corresponding links for the next level
            Node head = leftmost;
            
            while (head != null) {
                
                // CONNECTION 1
                head.left.next = head.right;
                
                // CONNECTION 2
                if (head.next != null) {
                    head.right.next = head.next.left;
                }
                
                // Progress along the list (nodes on the current level)
                head = head.next;
            }
            
            // Move onto the next level
            leftmost = leftmost.left;
        }
        
        return root;
    }
}
```

```python [solution2-Python]
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        if not root:
            return root
        
        # Start with the root node. There are no next pointers
        # that need to be set up on the first level
        leftmost = root
        
        # Once we reach the final level, we are done
        while leftmost.left:
            
            # Iterate the "linked list" starting from the head
            # node and using the next pointers, establish the 
            # corresponding links for the next level
            head = leftmost
            while head:
                
                # CONNECTION 1
                head.left.next = head.right
                
                # CONNECTION 2
                if head.next:
                    head.right.next = head.next.left
                
                # Progress along the list (nodes on the current level)
                head = head.next
            
            # Move onto the next level
            leftmost = leftmost.left
        
        return root 
```

**复杂度分析**

* 时间复杂度：$O(N)$，每个节点只访问一次。 

* 空间复杂度：$O(1)$，不需要存储额外的节点。