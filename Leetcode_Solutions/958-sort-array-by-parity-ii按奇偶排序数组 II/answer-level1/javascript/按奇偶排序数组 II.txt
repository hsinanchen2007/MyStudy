*法一：奇偶分开*
```js
var sortArrayByParityII = function(A) {
    let arr1 = []
    let arr2 = []
    A.forEach((item,index) => {
        if(item % 2 === 0) {
            arr1.push(item);
        } else {
            arr2.push(item);
        }
    });
    A.forEach((item, index) => {
        if(index % 2 !== 0) {
            A[index] = arr2.pop();
        } else {
            A[index] = arr1.pop();
        }
    });
    return A;
};
```
*法二： 双指针*
```js
var sortArrayByParityII = function(A) {
    let j = 1;
    for(let i = 0; i < A.length - 1; i = i + 2) {
        if((A[i] & 1) !== 0) { // 当A[i]是奇数时
            while((A[j] & 1) !== 0) {
                j += 2;
            }
            [A[i], A[j]] = [A[j], A[i]];
        }
    }
    return A;
};
```
