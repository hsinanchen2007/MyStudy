### 参考别的大佬的解学到很多：
1. API的使用sort
2. 第二个是我的原解，做烦了
```javascript
const verticalTraversal = root => {
    if(!root) return [];
    const cords = []; // 这里定义成数组，如果用set和add，会增加时间复杂度(add为O(1))
    dfs(root, cords, 0, 0);
    const ordered = cords.sort((a, b)=> {
        if(a[0] === b[0]) {
            if(a[1] === b[1]) return a[2] - b[2];
            return b[1] - a[1];
        }
        return a[0] - b[0];
    })
    
    let ans = [];
    let prevX = null, idx = 0;
    for(let i=0; i<ordered.length; i++) {
        const [x, y, val] = ordered[i];
        if(x !== prevX) {
            idx = ans.push([]) - 1;
            prevX = x;
        }
        ans[idx].push(val);
    }
    return ans;
};

function dfs(root, cords, x, y) {
    if(!root) return;
    cords.push([x, y, root.val]);
    dfs(root.left, cords, x-1, y-1);
    dfs(root.right, cords, x+1, y-1);
}
```
### 原解：
1. 采用前序遍历
2. 两种节点的存放： 
    1. 用于记录节点和坐标的对应关系：{ 节点: [x坐标, y坐标] } 
    2. 用于遍历时的顺序：{ x坐标: [y坐标] } 
3. 反思：如果更好地使用sort可以避免无用的数据结构和排序以及各种复杂度上的浪费

```javascript
const verticalTraversal = function(root) {
    if(!root) return [];
    let cords = {};
    getCords(root, cords, 0, 0);
    return orderCords(cords);
};

const getCords = function(root, cords, x, y) {
    if(!root) return;
    cords[root.val] = [x, y]; // 节点: [x坐标, y坐标] {3: [1,2], 4: [1,2]} 
    getCords(root.left, cords, x-1, y-1);
    getCords(root.right, cords, x+1, y-1);
}

const orderCords = function(cords) {
    if(!Object.keys(cords).length) return [];
    let cordsTemp = {}; // 存放临时的{x坐标: [y坐标]} 节点
    let res = [];
    
    for(const [x, y] of Object.values(cords)) {
        if(typeof cordsTemp[x] === 'undefined') cordsTemp[x] = []; // 当没有x坐标，则初始化x坐标对应y坐标数组
        cordsTemp[x].push(y); // 乱序{1:[5,4,8], 0:[2,3,1]}
        cordsTemp[x].sort((a,b)=> b-a); // 数组排序(y是由高到低排列的)：{1:[8,5,4] 0:[3,2,1]} 
    }
    // 对象排序输出：{0: [], 1: [], 2: []}
    for(const x of Object.keys(cordsTemp).sort((a,b)=> a-b)) {
        // 建立y的测试对象，如果x恒定的情况下，y存在多次则continue跳过，因为sameCordNodes会返回整个相同坐标的排序数组
        let verti = [], yDupTest = [];
        for(let y=0; y<cordsTemp[x].length; y++) {
            if(yDupTest.indexOf(cordsTemp[x][y]) !== -1) continue;
            verti = verti.concat(sameCordNodes(cords, x, cordsTemp[x][y]));
            yDupTest.push(cordsTemp[x][y]);
        }
        res.push(verti);
    }
    return res;
}

// 看是否有相同坐标，如果有则输出大小排列的数组，没有则输出单个元素的数组
const sameCordNodes = function(cords, x, y) {
    if(!Object.keys(cords).length) return;
    let same = [];
    for(const [key, val] of Object.entries(cords)) {
        // 强制把x和y转为数字
        if(+x === val[0] && +y === val[1]) same.push(key);
    }
    return same.sort((a,b)=> a-b); // 从小到大排序
}
```