### 解题思路
1. 连接n个点至少需要n-1 根线，如果不够n-1直接返回-1
2. 初始化每个点的头结点是自己
3. 遍历数组，给每一组两个数连线
4. 如果两个点的头结点一致，则说明已经连在一起了，否则选择一个点作为共同的头结点
5. 从0开始查找每个点的头结点是不是自己，如果是自己则说明是一个独立的圈
6. 如果全部连在一起则count == 1，否则超过1个圈就是需要连接n-1根线连接起来
![image.png](https://pic.leetcode-cn.com/a051b7b50678166c8ca1a6c14517aa7071ae9c3a6898d7d3a4509fd46ede0e86-image.png)

### 代码

```java
class Solution {
    private int[] father;

    public int makeConnected(int n, int[][] connections) {
        if (n - 1 > connections.length) {
            return -1;
        }
        int count = 0;
        father = new int[n];
        for (int i = 0; i < n; i++) {
            father[i] = i;
        }
        for (int i = 0; i < connections.length; i++) {
            union(connections[i][0], connections[i][1]);
        }
        for (int i = 0; i < n; i++) {
            if (findFather(i) == i) {
                count++;
            }
        }
        return count - 1;
    }

    //递归找到 i 的头结点
    public int findFather(int i) {
        if (father[i] == i) {
            return i;
        } else {
            father[i] = findFather(father[i]);
            return father[i];
        }
    }

    //将连个节点连在一起
    public void union(int a, int b) {
        int i = findFather(a);
        int j = findFather(b);
        if (i != j) {
            father[i] = j;//选一个点作为共同的父节点
        }
    }
}
```