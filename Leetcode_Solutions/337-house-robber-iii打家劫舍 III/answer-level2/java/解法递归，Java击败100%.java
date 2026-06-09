
自底而上，保证每个选择都是当前选择中的最优解。
对于每一个节点，都有选中和不选中两种情况。
分别计算出选中时可获得的最大利益，与不选时获取的最大利益并返回给上级。


```java
    int[] arr = find(root);
```
arr[0] 是选中当前节点时可获得的最大值
arr[1] 是不选中此节点时可获得的最大值


## find函数详解

### 非空判断
如果当前节点为null, 则其选中不选中都能获取的最大值都是0
```java
    if(node == null){
        return new int[]{0 , 0};
    }
```

### 获取子字节选中与非选中的最大值数据

要判断当前节点是否应该选中，我们首先要知道其子节点的最大值数据
```java
    int[] l = find(node.left)
    int[] r = find(node.right)
```

### 选中最大值
当节点被选中时，其子节点一定是非选中状态。
则其最大值 =  节点值 + 左子节点非选中的最大值 + 右子节点非选中的最大值
```java
    node.val + l[1] + r[1]
```
### 未选中最大值
当节点未被选中时，其子节点无需确认是否被选中，只关心最大值
其最大值 = 左子节点能获取的最大值 + 右子节点能获取的最大值
```java
    Math.max(l[0], l[1]) +  Math.max(r[0], r[1])
```

## 完整代码

```java
    public int rob(TreeNode root) {
        int[] arr = find(root);
        return Math.max(arr[0], arr[1]);
    }

    private int[] find(TreeNode node) {
        if(node == null){
            return new int[]{0 , 0};
        }
        int[] l = find(node.left);
        int[] r = find(node.right);
        return new int[] {
                node.val + l[1] + r[1],
                Math.max(l[0], l[1]) +  Math.max(r[0], r[1])
        };
    }
```   




