### 回溯算法框架（借鉴评论里的大神）
直接上回溯算法框架。解决一个回溯问题，实际上就是一个决策树的遍历过程。你只需要思考 3 个问题：

1、路径：也就是已经做出的选择。
2、选择列表：也就是你当前可以做的选择。
3、结束条件：也就是到达决策树底层，无法再做选择的条件。


```
// 代码框架
result = []
def backtrack(路径, 选择列表):
    if 满足结束条件:
        result.add(路径)
        return

for 选择 in 选择列表:
    做选择
    backtrack(路径, 选择列表)
    撤销选择
```
注意最后撤销选择的操作，在js中需要注意引用数据类型的传递与撤销。

```
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let len = candidates.length;
    if(len == 0)
        return candidates;
    // 箭头函数的使用
    candidates.sort((a, b) => {return a-b});
    // 存储每条路径
    var path = [];
    // 存储所有路径的总和
    var res = [];
    // 回溯算法
    let judepath = (path, start, target) => {
    // 1.先写递归终止条件
    if(target == 0) {
        // 另一种表示方法
        res.push(path.slice());
        return;
    }

    for(let i = start; i < len; i++) {
        // 不能直接操作target 让他每次都随着减元素变小，因为target是全局变量，这样会影响下一次操作。
        let risdul = target - candidates[i];
        // 2. 剪枝条件
        if(risdul < 0) {
            // 跳出整个循环，而不是仅仅本次循环，后面不符合要求的数字也不需要判断了。
            break;
        } 
        // 3. 把此次路径加入
        path.push(candidates[i]);
        // 搞不懂为什么都要把path通过slice()方法全部传给下一次递归
        // 猜测是因为数组是引用数据类型，这样传入的是path的地址
        // 进入下一次选择
        judepath(path, i, risdul);
        path.pop();    
    }
}
    judepath(path, 0, target);
    return res;

};
```
注意传值过程的两种表示
```
// 第一种:将path传给res时，是将path通过slice()方法全部截取再压入res中
res.push(path.slice());
judepath(path, i, risdul);

// 第二种:直接将path压入res中
res.push(path);
// 进行递归时，每次传入path全部截取后的数组，因为slice()方法不改变原数组，返回一个子数组。
judepath(path.slice(), i, risdul);
```
