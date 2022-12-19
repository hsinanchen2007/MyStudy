
记录每一层遍历的结构，然后判断是否是回文字符。
注意标记null的情况
```
var isSymmetric = function(root) {
    let arr = [root]
    let memoArr = []
    let index = 0
    // 关键就是用count记录一层的节点个数，然后阻断arr继续遍历，不然arr是会到整个树遍历玩
    while(arr.length>0){
        let count = arr.length
        memoArr[index] = []
        while(count--){
            let node = arr.shift()
            // n是添加的对null的标记 不然[1,2,2,null,3,null,3]也会对称
            if(node == 'n'){
                memoArr[index].push(node)
            }else if(node){
                memoArr[index].push(node.val)
                if(node.left){
                    arr.push(node.left)
                }else{
                    arr.push('n')
                }
                if(node.right){
                    arr.push(node.right)
                }else{
                    arr.push('n')
                }
            }
        }
        index++
    }

    return memoArr.every((arr)=>{
        let s = arr.join('')
        return arr.reverse().join('') == s
    })

};
```
