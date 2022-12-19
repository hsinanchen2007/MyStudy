# 一、递归
```
var levelOrderBottom = function(root) {
    let temp = [];
    let push = (node, i) => {
        if(node){
            if(!temp[i]) temp[i] = [];
            temp[i].push(node.val);
            push(node.left, i + 1);
            push(node.right, i + 1);
        }
    }
    push(root, 0)
    return temp.reverse();
};
```

# 二、迭代
```
var levelOrderBottom = function(root) {
    if(!root) return [];
    let temp = [];
    let i = 0;
    let nodes = [[root]];
    while(true){
        temp[i] = [];
        nodes[i + 1] = [];
        nodes[i].forEach(node => {
            if(node){
                temp[i].push(node.val);
                nodes[i + 1].push(node.left);
                nodes[i + 1].push(node.right);
            }
        })
        if(nodes[i + 1].every(node => !node)) break;
        i++;
    }
    return temp.reverse();
};
```

```
