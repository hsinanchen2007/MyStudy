### 一、暴力法
从0开始，一个一个比较
#### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
   let sum = 0;
   let item = 0;
   while(sum <= x) { // 1、边界条件判断
       item ++;
       sum = item * item;
   }
   return item - 1; // 2、这里需要-1
}
```
#### 复杂度分析
时间复杂度: 0(logN);
空间复杂度: O(1)

### 二、二分法
当 x≥2 时，它的整数平方根一定小于 x/2 且大于 0，即 0 < a < x/2;
套用二分法的经典模板。
#### 代码
```javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
   if(x< 2){
        return x;
    }
    let left = 2;
    let right = Math.floor(x/2);
    while(left <= right){
       let middle =  Math.floor(left +(right-left)/2);
       let num = middle*middle
       if(num == x){
           return middle;
       }else if(num > x){
           right = middle-1;
       } else {
           left = middle+1;
       }
    }
    return right; // 结束循环的时候肯定right小于left，这里要注意
}
```
#### 复杂度分析
时间复杂度: 0(logN);
空间复杂度: O(1)