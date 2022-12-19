### 解题思路
摸着dfs过河

### 代码

```javascript
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var flag = true
var canFinish = function (numCourses, prerequisites) {
    flag = true
    var a = new Array(numCourses)
    for (let i = 0; i < a.length; i++) {
        a[i] = new Array()
    }
    for (let i = 0; i < prerequisites.length; i++) {
        const e = prerequisites[i];
        a[e[1]].push(e[0])
        // a[e[0]].push(e[1])
    }
    var v = new Array(numCourses)
    for (let i = 0; i < a.length; i++) {
        dfs(a, i, v)
    }
    return flag
};
//遍历所有元素标志是被标记个数已经等于所有N,[只是遍历一张非闭环图、且连通]
//回溯是需要最终返回条件
function dfs(a, index, v) {
    if (v[index] == 1) {
        flag = false
        return
    }
    if (v[index] == -1) {
        return
    }
    var arr = a[index]//被遍历是index元素，邻接表这样都可尽可能遍历完本次所有元素
    v[index] = 1
    for (let i = 0; i < arr.length; i++) {//i就是课程
        const e = arr[i]
        dfs(a, e, v)//这里本质是遍历一条线
    }
    v[index] = -1//回溯的地方不再遍历
}
```