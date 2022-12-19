//一种JS版本的广度优先搜索解法，和官方推荐的思路基本一致。

```
var openLock = function (deadends, target) {
    //注意ES5不支持Set、Map等ES6中新增的数据结构。
    let deadSet = new Set(deadends);
    let que = [];
    que.push("0000");
    que.push("");
    let seen = new Set();
    seen.add("0000");
    var depth = 0;
    while (que.length != 0) {
        let node = que.shift();
        // console.log(que.length,"node")
        if (node == "") {
            depth ++;
            //注意这里如果不判断下que的长度，当死锁时会陷入死循环
            if (que.length > 0) {
                que.push("");
            }
        }
        else if (node == target) {
            return depth;
        }
        else if (!deadSet.has(node)) {
            for (let i = 0; i < 4; i++) {
                for (let d = -1; d <= 1; d += 2) {
                    let y = (Number(node.charAt(i)) + d + 10) % 10;
                    let newStr = node.substring(0, i) + y + node.substring(i + 1);
                    if (!seen.has(newStr)) {
                        seen.add(newStr);
                        que.push(newStr);
                    }
                }
            }
        }
    }
    return -1;
};

```

另外附上TypeScript的版本，TS的可读性我很喜欢：
```
/**
 * @param {string[]} deadends
 * @param {string} target
 * @return {number}
 */
var openLock = function(deadends:string[], target:string) {
    //注意ES5不支持Set、Map等ES6中新增的数据结构。
    let deadSet:Set<string> = new Set(deadends);
    let que:Array<string> = [];
    que.push("0000");
    que.push("");
    let seen:Set<string> = new Set();
    seen.add("0000");
    var depth = 0;
    while(que.length != 0){
        let node:string = <string>que.shift();
        // console.log(que.length,"node")
        if(node == ""){
            depth ++;
            //注意这里如果不判断下que的长度，当死锁时会陷入死循环
            if(que.length > 0){
                que.push("");
            }
        }else if(node == target){
            return depth;
        }else if(!deadSet.has(node)){
            for(let i = 0;i < 4;i ++){
                for(let d = -1; d <= 1;d +=2){
                    let y = (Number(node.charAt(i)) + d + 10) % 10;
                    let newStr = node.substring(0,i) + y + node.substring(i + 1);
                    if(!seen.has(newStr)){
                        seen.add(newStr);
                        que.push(newStr)
                    }
                }
            }
        }
    }
    return -1;
};
```


