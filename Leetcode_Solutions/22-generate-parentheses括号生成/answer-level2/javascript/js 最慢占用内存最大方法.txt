![image.png](https://pic.leetcode-cn.com/225e3734e73c7b93c9a37267868998a1a1d61367464aa4902a790b5099d28cc5-image.png)
```
var generateParenthesis = function(n) {
    // 找 f(n) 与f(n - 1) 的关系
    // 发现规律是: f(n) 是f(n - 1)的所有答案中进行插空、去重后得来的
    // 找到规律后  动态规划 从f(1) 开始一直算到f(n) 

    // 插空法 在每一个间隙插入一个(),包括左右边界
    /* 以下括号的数字仅仅是为了区分插入的() 和已有的()
    * n = 1   (1)
    * n = 2   (1) =>  (2)(1)  (1(2)) (1)(2)  ,去重 => ()()  (())
    * n = 3   (2)(2)  (2(2))  => (3)(2)(2)  (2)(3)(2)  (2)(2)(3)  (3)(2(2)) ((3)2(2)) (2(2(3))) (2(2)(3)) (2(2))(3)  去重  => ()()()   ()(()) (()()) ((())) (()()) (())()  
    */
    
    var index = 1
    var res = []
    var temp = []
    while (index <= n) {
        if (index === 1) {
            res = ['()']
        } else {
            // 清空
            temp.splice(0, temp.length)
            
            let len = res.length
            for (let i = 0;i < len;i++) {
                temp.push(handle(res[i]))
            }
            
            // temp二维数组扁平化
            temp = flatten(temp)
            
            // 去重
            res = [... new Set(temp)]
        }
        index++
    }
    
    // console.log(res)
    return res
};
function handle (str) {
    var res = []
    var len = str.length
    var arr = str.split('')
    for (let i = 0;i < len;i++) {
        let tempArr = [...arr]
        tempArr.splice(i, 0, '()')
        res.push(tempArr.join(''))
    }
    
    // 头部
    res.push('()' + str)
    
    return res
}
function flatten (arr) {
    var res = []
    var len = arr.length
    for (let i = 0;i < len;i++) {
        if (Object.prototype.toString.call(arr[i]) === '[object Array]') {
            res = res.concat(flatten(arr[i]))
        } else {
            res.push(arr[i])
        }
    }
    return res
}
```

