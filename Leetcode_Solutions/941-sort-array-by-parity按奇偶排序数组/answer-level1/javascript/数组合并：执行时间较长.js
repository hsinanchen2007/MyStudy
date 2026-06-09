### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number[]}
 */
var sortArrayByParity = function(A) {
    let B=[];
    let C=[];
    for(let i=0;i<A.length;i +=1){
        if(A[i]%2 === 0 ){
            B.push(A[i]);
        }else{
            C.push(A[i]);
        }
    }
    B = B.concat(C)
    return B
};
```定义两个数组分别装偶数奇数，然后concat合并即可。但是考虑到concat返回的是被连接数组的副本，有影响。