辅助函数getSum判断i，j各位数之和是否 <= k
从起始点（0,0）向右和下方向逐个遍历判断，而这种方式会使遍历过的点经由另一个方向的点再次遍历，比如一个2*2的表格，起始点（0,0）开始会依次判断（0,0）、（0,1）、（1,1）、（1,0）、（1,1） 可以看到（1,1）判断了两次，而这在遍历中不仅会使结果超出实际结果还会使遍历次数增加很多。
所以我增加了一个arr二维数组记录遍历过的点，每到达一个点将arr[i][j]置为true 提高效率
```
var movingCount = function(m, n, k) {
    let res = 0
    let arr = []
    let getSum = function(num1, num2) { //判断两个数位数之和是否 <= k
        let sums = 0
        while(num1 !== 0 || num2 !== 0) {
            if(num1 !== 0) {
                sums += num1 % 10
                num1 = Math.floor(num1 / 10)
            }else {
                sums += num2 % 10
                num2 = Math.floor(num2 / 10)
            }
        }
        if(sums <= k) return true
        else return false
    }
    let find = function(i, j) {
        if(!arr[i]) arr[i] = new Array()
        if(arr[i][j]) return //已经遍历过的点直接return
        else arr[i][j] = true
        if(getSum(i, j)) {
            res++
            if(i + 1 < m) find(i + 1, j) //判断右方向的点是否越界
            if(j + 1 < n) find(i, j + 1) //判断下方向的点是否越界
        }
    }
    find(0, 0)
    return res
};
```
