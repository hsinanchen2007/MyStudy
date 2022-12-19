# 1. 解数独
因为年少时喜欢做数独，所以很清楚数独的解题思路，简单总结如下：
1. 先确定每个空格可能取值
2. 填写只剩一种可能取值的空格
3. 更新其他同行，同列，同9宫格的空格可能取值
4. 重复【2】【3】，出现3中情况：
- 没有空格 -- 解题成功
- 任一空格不存在任何可能的取值 -- 本题无解
- 剩下的空格都存在多个可能取值
5. 尝试假定某个空格的值，重复【2】【3】【4】

# 2. 算法和数据结构
有了解题思路，接下来就可以设计算法和数据结构了，注意到上述解题的过程可以简化为【符合条件？出列：重新入队】，因此考虑用队列。另外注意到会遇到步骤【5】，因此需要在检查到整个队列没有符合要求的时候设定一个假设值，当推出无解时回溯到假设前的状态，然后设定下一个假设值。用一个队列记录剩余待求解的空格索引，再用一个哈希表记录每个空格可能的取值。

```javascript
/**
 * deep clone
 */
var deepClone = function(obj) {
    if (typeof obj!=='object' || obj===null) {
        return obj;
    }
    let ret = Array.isArray(obj) ? [] : {};
    for (let k in obj) {
        ret[k] = deepClone(obj[k]);
    }
    return ret;
}

/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let _q = [],_hash = {}, allow = ['1','2','3','4','5','6','7','8','9'];
    // 初始化
    for (let i=0;i<9;i++) {
        for(let j=0;j<9;j++) {
            if (board[i][j] == '.') {
                // 初始化空格的所有可能值
                _hash[i*9+j] = Object.assign([], allow);
            } else {
                // 已填入的值
                _hash[i*9+j] = [board[i][j]];
            }
            _q.push(i*9+j);
        }
    }
    // 只有唯一解，否则会死循环
    function slove(q, hash) {
        while (q.length > 0) {
            let len = q.length;
            // 队尾删除避免索引混乱 （顺序好像也是可以的。。）
            for (let idx = len-1; idx >=0; idx--) {
                if (hash[q[idx]].length == 0) {
                    return false; // 无任何可能取值，本次无解
                }
                if (hash[q[idx]].length == 1) {
                    // 还原索引位置
                    let i = Math.floor(q[idx]/9), j = q[idx]%9;
                    board[i][j] = hash[q[idx]][0];
                    delete hash[q[idx]];
                    q.splice(idx,1);
                    // 删除关联位置的可能取值
                    for(let a in hash) {
                        let r = Math.floor(a/9), c = a%9;
                        if (r==i || c==j || (Math.floor(i/3)==Math.floor(r/3) && Math.floor(j/3)==Math.floor(c/3))){
                            // delete
                            let exist = hash[a].indexOf(board[i][j]);
                            if (exist !== -1) {
                                hash[a].splice(exist, 1);
                            }
                        }
                    }
                } else {
                    len--;  // 计数，
                }
            }
            // 出现多个位置多个可能取值，进入步骤【5】
            if(len == 0) {
                // 出现每个位置都有多个可能值，逐个假设尝试求解
                for (let n =0; n<hash[q[0]].length; n++) {
                    // 克隆状态，循环尝试求解
                    // 之前用了Object.assign()浅拷贝导致我调试了n久
                    let cloneHash = deepClone(hash);
                    let cloneQ = deepClone(q);
                    // 预先设定一个值
                    cloneHash[cloneQ[0]] = [hash[q[0]][n]];
                    if (slove(cloneQ, cloneHash)) {
                        return true;    // 解题成功，否则回溯进入下一个循环
                    }
                }
                // 所有可能值都失败，无解
                return false;
            }
        }
        return true;
    }
    slove(_q, _hash)
    return board;
};
```

# 3. 结果和优化

```
执行用时 :104 ms, 在所有 JavaScript 提交中击败了63.07%的用户
内存消耗 :37.7 MB, 在所有 JavaScript 提交中击败了61.64%的用户
```
ac之后去看了大神们的题解，受到启发可以使用位标记代替字符串数组进行优化，也就是将`[1,2,3,4,5,6,7,8,9]`替换为二进制 `11111111`，比如`[1,5,6,8]`可以表示成`100011010`,删除取值可以改为位与运算：
删除5: `allow & 111101111`
判断取值为空： `allow == 0`
判断唯一取值好像有点麻烦，需要判断是否2的整数幂。刚好需要使用数字字典，判断是否在字典中就可以了
下面是优化后的代码：
```
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    let _q = [],_hash = {}, alpha = {
        1: '1',
        2: '2',
        4: '3',
        8: '4',
        16: '5',
        32: '6',
        64: '7',
        128: '8',
        256: '9'
    };
    for (let i=0;i<9;i++) {
        for(let j=0;j<9;j++) {
            if (board[i][j] == '.') {
                _hash[i*9+j] = 511;// 111111111
            } else {
                _hash[i*9+j] = 1<<([board[i][j]]-1);
            }
            _q.push(i*9+j);
        }
    }
    // 只有唯一解，否则会死循环
    function slove(q, hash) {
        while (q.length > 0) {
            let len = q.length;
            // 顺序删除导致索引错误
            for (let idx = len-1; idx >=0; idx--) {
                if (hash[q[idx]] == 0) {
                    return false;
                }
                // 存在于alpha说明值唯一
                if (alpha.hasOwnProperty(hash[q[idx]])) {
                    let i = Math.floor(q[idx]/9), j = q[idx]%9;
                    board[i][j] = alpha[hash[q[idx]]];
                    // js的位元算好像最多16位？
                    let mask = 65535^hash[q[idx]];
                    delete hash[q[idx]];
                    q.splice(idx,1);
                    for(let a in hash) {
                        let r = Math.floor(a/9), c = a%9;
                        if (r==i || c==j || (Math.floor(i/3)==Math.floor(r/3) && Math.floor(j/3)==Math.floor(c/3))){
                            // delete
                            hash[a] = mask & hash[a];
                        }
                    }
                } else {
                    len--;
                }
            }
            if(len == 0) {
                // 出现每个位置都有多个可能值，逐个假设尝试求解
                let count=0, allow = hash[q[0]];
                while (allow > 0) {
                    if (allow%2==1) {
                        // 克隆状态，循环尝试求解
                        let cloneHash = Object.assign({}, hash);
                        let cloneQ = Object.assign([], q);
                        cloneHash[cloneQ[0]] = 1<<count;
                        if (slove(cloneQ, cloneHash)) {
                            return true;
                        }
                    }
                    allow = allow>>1;
                    count++;
                }
                // 所有可能值都失败，无解
                return false;
            }
        }
        return true;
    }
    // console.log(slove(_q, _hash));
    slove(_q, _hash);
    return board;
};
```
优化后的ac结果：
![8305666E765457A908DC2F4D8A59E764.jpg](https://pic.leetcode-cn.com/3444a33512b8c04cc3cd85e612219c8c19ab783b8ea17c7eb38ea4dc2142790a-8305666E765457A908DC2F4D8A59E764.jpg)


