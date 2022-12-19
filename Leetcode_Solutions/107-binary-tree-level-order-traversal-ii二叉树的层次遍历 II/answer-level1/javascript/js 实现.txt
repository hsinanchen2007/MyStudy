```
var levelOrderBottom = function(root) {
    let res = [];
    if(root === null) return res;

    let queue = [];
    let curr = root;
    queue.push(root);

    let level = 0;
    while(queue.length !== 0){
        res.push([]);
        let len = queue.length;
        for(let i=0;i<len;i++){
            curr = queue.shift();
            res[level].push(curr.val);
            curr.left && queue.push(curr.left);
            curr.right && queue.push(curr.right);
        }
        level++
    }
    return res.reverse()
};
```
