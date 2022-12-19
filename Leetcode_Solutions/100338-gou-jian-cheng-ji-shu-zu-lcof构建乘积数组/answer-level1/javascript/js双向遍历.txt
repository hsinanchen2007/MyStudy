### 解题思路
left从左往右遍历，逐个求出从索引0对应值一直乘到 到当前索引的乘积结果；
right从右往左遍历，逐个求出从最后一个值乘到当前值得乘积结果。

然后 结果就是b[i] = left[i-1] *right[i+1];

### 代码

```javascript
/**
 * @param {number[]} a
 * @return {number[]}
 */
//暴力法
// var constructArr = function(a) {
//     let b=[];
//     let pre=1
//     a.forEach((v,i)=>{
//         let j=i+1;
//         let muti=1;
//         while(j<a.length){
//             muti *=a[j];
//             j++;
//         }

//         b.push(pre*muti);
//         pre *= a[i];
//     })

//     return b;
// };

//对称遍历
var constructArr = function(a) {
    let left=[];
    let right=[];
    let len = a.length;
    for(let i = 0;i < len ; i++){
        let j=len-i-1;
        if(i == 0){
            left[i] = a[i];
            right[j] = a[j];
        }else{
            left[i] = left[i-1] * a[i];
            right[j] = right[j+1] * a[j]; 
        }
       
    }
    // console.log(left);
    // console.log(right);

    let b=[];
    for(let i=0;i<len;i++){
        if(i===0)b[i]=right[i+1];
        else if(i===len-1)b[i]=left[i-1];
        else b[i] = left[i-1] *right[i+1];
    }
    return b;
};
```