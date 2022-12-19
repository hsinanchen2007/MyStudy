


```
var copyRandomList = function(head) {
    //对象记录
    const map = {};
    
    function recur(node){
        if(!node){
            return null
        }
        //判断是否存在
        if(map[node.val]){
            return map[node.val]
        }
        //创建node
        let res = new Node(node.val);
        //存储node
        map[node.val] = res;

        res.next = recur(node.next);

        res.random = recur(node.random)

        return res
    }
    return recur(head)
};
```
