### 解题思路
![image.png](https://pic.leetcode-cn.com/1e3a37067bc15b56b0ff1f26a7cf605ce77ca899435eeb89cbb9d2c77a4bda2d-image.png)

- 通过 num = num * 2 + A[i] 将二进制转化成十进制
- 除余进行判断，然后最后 %10 进行降级，降低计算量

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean[]}
 */
var prefixesDivBy5 = function(A) {
    let num = 0
    let arr = []
    for(let i = 0; i < A.length; i++){
        num = num*2 + A[i]
        if(num % 5 == 0){
            arr[i] = true
        }else{
            arr[i] = false
        }
        num = num % 10
    }
    return arr
};
```