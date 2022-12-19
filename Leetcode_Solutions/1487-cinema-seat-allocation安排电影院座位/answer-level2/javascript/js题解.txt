```
// 每一行上，可以放几个家庭，一共就那么几种情况，枚举就可以。
let rowCnt = (arr) => {
    let a = [1,2,3,4,5,6,7,8,9,10];
    if (!arr.length) return 2;
    // 中间的4个座位。如果都没有预定，要考虑23和89。只有2389都没预定才返回2.
    if(!arr.includes(4) && !arr.includes(5) && !arr.includes(6) && !arr.includes(7)){
        if(arr.includes(2) || arr.includes(3) || arr.includes(8) || arr.includes(9)){
            return 1;
        }else{
            return 2;
        }
    }
    let c = 2;
    if (arr.includes(2) || arr.includes(3) || arr.includes(4) || arr.includes(5)){
        c--;
    }
    if(arr.includes(6) || arr.includes(7) || arr.includes(8) || arr.includes(9)){
        c--;
    }

    return c;
};

var maxNumberOfFamilies = function(n, reservedSeats) {
    let cnt = 0;
    reservedSeats.sort((a, b) => {
        return a[0] - b[0]
    });
    let arr = [reservedSeats[0][1]]
    let curRow = reservedSeats[0][0]
    // 空行的问题。某些整行都没人预定，则结果数 + 2 * 空行数
    if (curRow !== 1){
        cnt += 2 * (curRow - 1);
    }
    for(let i = 1; i < reservedSeats.length; i++){
        if(reservedSeats[i][0] === curRow){
            arr.push(reservedSeats[i][1])
        }else{
            if (reservedSeats[i][0] - curRow !== 1){
                cnt += 2 * (reservedSeats[i][0] - curRow - 1); // 中间空行
            }
            cnt += rowCnt(arr);
            arr = [reservedSeats[i][1]]
            curRow = reservedSeats[i][0]
        }
    }
    cnt += rowCnt(arr);
    // 最后一个有预定的行的 后面的空行
    if (curRow !== n){
        cnt += 2 * (n - curRow)
    }
    return cnt;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解