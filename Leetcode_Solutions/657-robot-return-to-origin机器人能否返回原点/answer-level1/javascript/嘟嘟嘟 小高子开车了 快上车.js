```javascript []
/**
 * @param {string} moves
 * @return {boolean}
 */
// 解题思路 1.题目要求返回机器人是否会回到原点 
//         2.判断上和下 左和右的步数是否相同 即可
//         3.鄙人采用的是 字符串的match() 方法 返回符合正则匹配的结果集 敲重点 如果没有 则返回null
//         4.有更好方法的小伙伴请积极发言 不用举手 互相学习

// 执行结果：通过 显示详情
// 执行用时 :104 ms, 在所有 JavaScript 提交中击败了68.39%的用户
// 内存消耗 :40.5 MB, 在所有 JavaScript 提交中击败了20.17%的用户

var judgeCircle = function(moves) {
    let up = moves.match(/U/g)?moves.match(/U/g):[]
    let down = moves.match(/D/g)?moves.match(/D/g):[]
    let left = moves.match(/L/g)?moves.match(/L/g):[]
    let right = moves.match(/R/g)?moves.match(/R/g):[]
    
    if(up.length == down.length && left.length == right.length){
        return true
    }else{
        return false
    }
};
```

