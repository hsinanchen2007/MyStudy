### 解题思路
- 双指针定义 奇数位，偶数位
- 将通过 forEach 进行遍历，将对应数字放在对应的位置上

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function(A) {
    let arr = []
    let odd = 1
    let even = 0
    A.forEach(item => {
        if(item % 2 == 0){
            arr[even] = item
            even += 2
        }else{
            arr[odd] = item
            odd += 2
        }
    })
    return arr
};
```