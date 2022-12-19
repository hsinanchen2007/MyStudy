### 解题思路
定义一个当次发糖个数a，下标b，c为num_people位数的数组，填充0；
用candies依次减当前发出去的糖，最后加剩余糖与a之中小的那个；
b下标跟着++循环，当等于人数时，回到0。

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let a=1,b=0,c=new Array(num_people).fill(0);
    while(candies>0){
        if(b===num_people){
            b=0
        }
        c[b]+=(candies>a?a:candies)
        candies-=a++
        b++
    }
    return c
};
```