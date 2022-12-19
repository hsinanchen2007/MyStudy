- 定义一个数组用来存放每个遍历过的节点。
- 定义递归函数，每次运行的时候把当前的节点push进数组里面，注意递归的终止条件，否则会造成死循环。
- 逆转节点数组，然后依次调用节点的打印方法。
```js
var printLinkedListInReverse = function(head) {
    let res = []
    var print = head => {
        res.push(head)
        if(head.getNext()) {
            return print(head.getNext())
        }
    }
    print(head)
    res = res.reverse()
    res.forEach(value => {
        value.printValue()
    })
};
```
![image.png](https://pic.leetcode-cn.com/3045d3bf7b86bef31e54debcc4470e6cbbfef56ec8df9b71d632278df9bf4687-image.png)
