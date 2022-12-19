### 解题思路
1. 以1x2b为例，看下图
           1x2b
    1x2b           1X2b
1x2b    1x2B   1X2b    1X2B

2. 可见最后一排的叶子即为最终所有的组合
3. 所以可以使用二叉树的BFS算法获取   

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var letterCasePermutation = function(S) {
    const REG = /[A-Za-z]/;
    function collect(S, index){
        if(index >= S.length)return [S]; //到了叶子节点，也就是我们需要收集的其中一个组合
        const letter = S.charAt(index);
        let pos = index+1;
        if(REG.test(letter)){
            const r = S.slice(0,index)+letter.toLowerCase()+S.slice(index+1);
            const arr = collect(r, pos); //左边节点 
            const l = S.slice(0,index)+letter.toUpperCase()+S.slice(index+1);
            return arr.concat(collect(l, pos)); //右边
        }else{
            return collect(S, pos); //如果当前的元素不是字母，原样返回
        }
    }
    const result = collect(S, 0);
    return result;
};
```