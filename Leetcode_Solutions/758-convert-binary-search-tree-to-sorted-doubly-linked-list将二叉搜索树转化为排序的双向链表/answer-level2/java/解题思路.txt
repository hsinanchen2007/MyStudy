中序遍历：
1： 左边叶子节点遍历到底，结束，找到初始节点。
2： 访问root节点，同时关联左侧叶子节点与root节点。即关联root的left链接，left的right链接
3:  并且记录每个最后访问的节点。
4： 访问右侧节点，同时关联root与右侧节点。即关联右侧节点的left链接。root的right的链接
整个处理流程保持左-中-右。同时通过lastnode记录上次访问节点。即lastnode也保持着left-root-right。