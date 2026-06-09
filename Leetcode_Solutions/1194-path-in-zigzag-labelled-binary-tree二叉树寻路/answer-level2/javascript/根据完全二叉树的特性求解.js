### 思路
如果是正常递增序列的完全二叉树有如下特点:
```
                   1
        2                    3
   4         5          6          7 
8     9   10    11   12    13   14    15 
```

- 父节点序列=`向小取整(子节点序列/2)`
- 当前节点所在层级=`向大取整(当前节点序列值+1再对2求指数)`
- 第n层的所有节点的序列值范围[2的(n-1)次方, 2的n次方-1]

针对该题，只需要通过一个循环，每次取label的父节点的序列值即可。那么核心工作就是如何来获取“之”字型完全二叉树的父节点的序列值。

可以发现，“之”字二叉树父节点序列值有如下特点：
第n层label节点的父节点序列值其实就是`2的(n-1)次方 + 2的n次方-1 - 向小取整(label/2)`

那么解题步骤如下：

1. `向小取整(label/2)`获得正常的父节点序列值
2. `2的(n-1)次方 + 2的n次方-1 - 向小取整(子节点序列/2)`得到新的父节点序列值
3. 将刚获取的父节点的序列值赋予label,继续步骤1

### 代码

```javascript
var pathInZigZagTree = function(label) {
  // 往大求整，减1的原因是while循环从其父节点所在层级开始
  let depth = Math.ceil(Math.log(label + 1) / Math.log(2)) - 1; 
  // console.log(depth);
  const path = [label];
  while(depth > 0) {
    const oldIndex = Math.floor(label / 2);
    if(oldIndex <= 0) break;
    const newIndex = Math.pow(2, depth) - 1 + Math.pow(2, depth - 1) - oldIndex;
    label = newIndex;
    path.unshift(newIndex);
    depth--;
  }
  return path;
};
```
