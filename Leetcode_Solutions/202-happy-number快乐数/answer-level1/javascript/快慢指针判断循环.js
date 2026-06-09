### 解题思路
对于一个循环，定义两个指针
快指针一次前进两步，慢指针一次前进一步
如果是循环，快指针和慢指针最终会相遇

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    var fast=n;
    var slow=n;
    do{
        slow=happySum(slow);
        fast=happySum(fast);
        fast=happySum(fast);  
    }while(slow!=fast);
    return slow==1;
};
function happySum(s){
    var sum=0;
    var bit;
    while(s>0){
        bit = s % 10;
        sum = sum + bit*bit;
        s = Math.floor(s/10);
    }
    return sum;
}

```