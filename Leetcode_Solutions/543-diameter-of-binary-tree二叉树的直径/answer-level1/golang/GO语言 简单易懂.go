 
设置一个全局变量保存当前的最大直径。
递归求每个结点的深度，同时，可以求出每个点的最大直径，再与当前最大直径进行比较，更新当前最大直径。
最后输出最大直径。

（力扣中直接使用GO的全局变量容易出错，所以这里用指针实现全局变量）

![image.png](https://pic.leetcode-cn.com/444829211cad9f90320d8c855cb59c37803ae2a9d786f3e3b75f1c5c34bd2f3c-image.png)
 
 
```

func diameterOfBinaryTree(root *TreeNode) int {
    m:=0
    max:=&m  //现有的最长直径
    if root==nil{
        return 0
    }
    depth(root,max)
    return *max
}


func depth(root *TreeNode,max *int)int{
      if root==nil{
        return 0
    }
    a:=depth(root.Left,max)
    b:=depth(root.Right,max)
    *max =int(math.Max(float64(a+b),float64(*max)))//此节点的直径和现有的最长直径比较
    return int(math.Max(float64(a),float64(b)))+1//返回深度
}
```
```
