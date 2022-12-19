- 剪枝,先排序,如果结果已经小于0了，则不管这次循环里面的值了
- 去重复: 在搜索的时候，需要设置搜索起点的下标 begin ，由于一个数可以使用多次，下一层的结点从这个搜索起点开始搜索
- 回溯: path进入下一次dfs的时候，先删掉上一次加在path的末尾的那个
```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let res = [];
    let len = candidates.length;
    candidates.sort((a,b) => a - b);
    dfs(candidates,len,target,0,[],res);
    return res;
};
const dfs = function(candidates,len,residue,begin,path,res) {
    if(residue === 0) {
        res.push(path);
        return;
    }
    for(let i = begin; i < len;i++) {
        if (residue - candidates[i] < 0) {
            break;
        }
        path.push(candidates[i]);
        // path.slice() 拷贝数组、防止改变原数组
        dfs(candidates, len, residue - candidates[i], i, path.slice(), res);
        // 回溯: 每次删掉末尾的这个，再进入下次循环
        path.pop();
    }
}
```