### 解题思路
先将根节点入队列，循环子元素依次入队列，控制出队列先后从左到右即可

### 代码

```javascript
var levelOrder = function(root) {
    if (!root) return [];

    let queue = [], res = [];
    queue.push(root);

    while (queue.length) {
        let len = queue.length, cur = [];

        while (len) {
            // 出队列
            let temp = queue.shift();
            cur.push(temp.val);

            let children = temp.children, i = 0;
            while (i < children.length) {
                queue.push(children[i]);
                i++;
            }
            len--;
        }
        res.push(cur);
    }
    return res;
};
```