## 方法

方法写的和大家大同小异，最初想的是层次遍历入队，各层中的点都逐一连接，觉得这道题太水了，结果发现要常数空间，有点惊讶。

后来发现依旧可以层次遍历，因为有 `next` 指针！加上树本身是完美二叉树，代码很容易写。

树：`[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14]`

![image.png](https://pic.leetcode-cn.com/9687f3263d0708fce8be76f32e264773e97bee72695ffa4ff6380676b65699c3-image.png)

* 第一层：无需操作；
* 第二层：
    * 根据父节点 0，1 -> 2；
* 第三层：
    * 根据父节点 1，3 -> 4；
    * 根据父节点 1 和 2，4 -> 5；
    * 根据父节点 2，5 -> 6；
* 第四层：
    * 根据父节点 3，7 -> 8；
    * 根据父节点 3 和 4，8 -> 9；
    * 根据父节点 4，9 -> 10；
    * 根据父节点 4 和 5，10 -> 11；
    * 根据父节点 5，11 -> 12；
    * 根据父节点 5 和 6，12 -> 13；
    * 根据父节点 6，13 -> 14；

每一层的遍历都可以通过上一层的 `next` 指针链进行遍历；

因此，我们只需要遍历当前层，即可将下一层的 `next` 调整完毕。

## 写法

遍历每一层：

* 起始：root 的最左子孙节点
* 遍历指针：我设置为叫 `worker` 的指针
* 结束：null

```java
public Node connect(Node root) {
    if (root == null) return null;
    Node level = root, worker = level;
    while(level.left != null) {
        worker.left.next = worker.right;
        if (worker.next == null) {
            level = level.left;
            worker = level;
        } else {
            worker.right.next = level.next.left;
            worker = worker.next;
        }
    }
    return root;
}
```