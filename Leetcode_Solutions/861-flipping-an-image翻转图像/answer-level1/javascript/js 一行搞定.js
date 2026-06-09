双指针发减少了内层循环的次数（1/2）；可以为什么用时比暴力破解法用的时间还长--这不科学

解法1：利用array.map--暴力破解
```
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    return A.map(i => i.map(j => (j^1)).reverse())
};
```
解法二：双指针
```
var flipAndInvertImage = function(A) {
    for (let i = 0; i < A.length; i++) {
        let endPonit = A[i].length -1;
        let startPonit = 0;
        while (startPonit < endPonit){
            [A[i][startPonit], A[i][endPonit]] = [A[i][endPonit] ^ 1, A[i][startPonit] ^ 1] //取反后交换前后指针位置的数字
            startPonit++ //更新指针
            endPonit-- //更新指针
        }
        if (startPonit === endPonit){//如果数组为奇数时：两个指针的位置是相同的，此时没有没有元素进行交换所以只需对其自身进行取反操作即可
            A[i][startPonit] = A[i][endPonit] ^ 1
        }
    }
    return A
};
```
求教：怎么计算时间及空间复杂度

