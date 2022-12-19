### 解题思路
此处撰写解题思路
1、创建一个长度为A.length的数组
2、遍历数组A，偶数放在偶数位，奇数放在奇数位
### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParityII = function(A) {
    let res= new Array(A.length).fill(0)
    let len = A.length
    for(let k=0 ,i=0, j=1; k<len; k++){
        if(A[k] % 2 == 0){
            res[i] = A[k]
            i+=2
        }else{
            res[j] = A[k]
            j+=2
        }
    }
    // console.log(res)
    return res
};
```