思想：其实就是中序的非递归，因为二叉排序树的中序遍历是有序的。
```js
var kthSmallest = function(root, k) {
    let stack = [];
    let p = root, count = 0;    // count 用来计数
    while(p || stack.length > 0) {
        while(p) {
            stack.push(p);
            p = p.left;
        }
        if(stack.length > 0) {
            p = stack.pop();
            ++count;
            if(count === k) // 当count与k相等，说明知道了第k个
                return p.val;
            p = p.right;
        }
    }
};
```

![微信图片_20200119211022.png](https://pic.leetcode-cn.com/4bd5644d64598a71dadf016b2c96a238cc55cffddc01dade7a97104282811a53-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200119211022.png)
