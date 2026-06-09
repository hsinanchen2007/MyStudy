### 解题思路
法官不相信任何人：把相信过其他人的放进一个数组
法官被所有人相信，把等于总人数 - 1的人放进一个数组
在被所有人相信的数组里面删掉相信过其他人的人

### 代码

```javascript
/**
 * @param {number} N
 * @param {number[][]} trust
 * @return {number}
 */
var findJudge = function(N, trust) {
    var stack = [];
    var fake = []
    if (N === 1){
        return N
    }
    for (var i = 1; i <= N; i++){
        var sum = 0;
        for ( var a = 0;a < trust.length; a++){
            if (i === trust[a][0]){
                fake.push(i)
            }
            if (i === trust[a][1]){
                sum++
                if (sum === N - 1){
                    stack.push(i)
                    continue
                }
            }
        }
    }
    if (stack.length === 0){
        return -1
    }
    for (var i = 0; i < stack.length; i++){
        for (var f = 0; f < fake.length; f++){
            if (stack[i] === fake[f]){
                stack.splice(i,1)
            }
        }
    }
    if (stack.length !== 0){
        return stack[0]
    }else{
        return -1
    }
};
```