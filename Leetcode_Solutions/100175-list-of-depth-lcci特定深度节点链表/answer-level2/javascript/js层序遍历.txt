```
var listOfDepth = function(tree) {
    let arr = [];
    let bfs = (nodeArr) => {
        let nextArr = [];
        let vhead = new ListNode()
        let node = vhead;
        for(let i = 0; i < nodeArr.length; i++){
            node.next = new ListNode(nodeArr[i].val);
            node = node.next;
            if (nodeArr[i].left){
                nextArr.push(nodeArr[i].left);
            }
            if(nodeArr[i].right){
                nextArr.push(nodeArr[i].right);
            }
        }
        arr.push(vhead.next);
        if (!nextArr.length) return;
        bfs(nextArr);

    };
    bfs([tree]);
    return arr;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解