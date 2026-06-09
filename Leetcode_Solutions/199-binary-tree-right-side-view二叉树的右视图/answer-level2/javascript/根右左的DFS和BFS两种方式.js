层序遍历, 每层获取到末端的节点后, 清空所有节点
```
var rightSideView = function(root) {
    if (!root) return [];
    let output = [];
    let queue = [root];
    while(queue.length) {
        let preStack = queue.pop();
        output.push(preStack.val);
        let len = queue.length;
        for(let i = 0; i < len; i++) {
            let anthorNode = queue.pop();
            if (anthorNode.right) {
                queue.unshift(anthorNode.right);
            }
            if (anthorNode.left) {
                queue.unshift(anthorNode.left);
            }
        }
        if (preStack.left) {
            queue.push(preStack.left);
        }
        if (preStack.right) {
            queue.push(preStack.right);
        }
    }
    return output;
};
```
根右左深度优先遍历, 记录当前遍历的节点层级,只取层级不一样的新节点,右节点优先
```
var rightSideView = function(root) {
    if (!root) return [];
    let output = [];
    let stack = [{
        node: root,
        index: 0
    }];
    while(stack.length) {
        let preStack = stack.pop();
        if (output.length == preStack.index) {
            output.push(preStack.node.val);
        }
        if (preStack.node.left) {
            stack.push({
                node: preStack.node.left,
                index: preStack.index + 1
            });
        }
        if (preStack.node.right) {
            stack.push({
                node: preStack.node.right,
                index: preStack.index + 1
            });
        }
    }
    return output;
};
```