### 最少代码解决, 缺点是这种递归写法会导致leetcode的栈溢出,
```javascript
function f(n) {
    if (n === 1) {
        return [[1]];
    }
    if(n === 2) {
        return [[1],[1, 1]];
    }
    else{
        const arr = f(n -1)[f(n-1).length - 1];
        const temp = [1];
        for (let i = 0; i<arr.length-1; i++){
            temp.push(arr[i]+ arr[i+1]);
        }
        temp.push(1);
        return [...f(n-1), temp];
    }
}
```