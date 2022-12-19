1、排序
2、候选数组的索引从下一位开始
3、主要是小剪枝的思想：候选数组有序，对于在递归树中发现重复分支，则进行剪枝
#### 一、排序后过滤掉同层中相同的元素
i > begin && candidates[i] == candidates[i - 1] 这行代码，参考某个大佬的解释:
这个避免重复当思想是在是太重要了。
这个方法最重要的作用是，可以让同一层级，不出现相同的元素。即
                  
```
                  例1
                  1
                 / \
                2    2          这种情况不会发生 但是却允许了不同层级之间的重复即：
               /      \
              5        5
                例2
                  1
                 /
                2      这种情况确是允许的
               /
              2  
```
                
为何会有这种神奇的效果呢？
首先 cur-1 == cur 是用于判定当前元素是否和之前元素相同的语句。这个语句就能砍掉例1。可是问题来了，如果把所有当前与之前一个元素相同的都砍掉，那么例二的情况也会消失。因为当第二个2出现的时候，他就和前一个2相同了。
                
那么如何保留例2呢？
就用cur > begin 来避免这种情况，你发现例1中的两个2是处在同一个层级上的，例2的两个2是处在不同层级上的。在一个for循环中，所有被遍历到的数都是属于一个层级的。我们要让一个层级中，必须出现且只出现一个2，那么就放过第一个出现重复的2，但不放过后面出现的2。第一个出现的2的特点就是 cur == begin. 第二个出现的2 特点是cur > begin.

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    let ans = [];
    let path = [];
    let len = candidates.length; 
    candidates.sort((a,b)=> a-b);
    dfs(candidates,target,0,len,ans,path)
    return ans;
};

const dfs = function(candidates,target,begin,len,ans,path) {
    if(target === 0) {
        ans.push(path);
        return;
    }
    for(let i = begin; i < len; i++) {
        // 大剪枝
        if(target - candidates[i] < 0) break;
        // 小剪枝
        if (i > begin && candidates[i] == candidates[i - 1]) continue; // 避免同级发生重复
        path.push(candidates[i]);
        dfs(candidates,target - candidates[i],i+1,len,ans,path.slice());
        path.pop();
    }
}
```
### 二、利用哈希表

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    let ans = [];
    let path = [];
    let len = candidates.length; 
    candidates.sort((a,b)=> a-b);
    dfs(candidates,target,0,len,ans,path)
    return ans;
};

const dfs = function(candidates,target,begin,len,ans,path) {
    if(target === 0) {
        ans.push(path);
        return;
    }
    let map = new Map();
    for(let i = begin; i < len; i++) {
        // 大剪枝
        if(target - candidates[i] < 0) break;
        // 小剪枝
        // if (i > begin && candidates[i] == candidates[i - 1]) continue;
        if(!map.get(candidates[i])) {
            map.set(candidates[i],true);
            path.push(candidates[i]);
            dfs(candidates,target - candidates[i],i+1,len,ans,path.slice());
            path.pop();
        }
    }
}
```