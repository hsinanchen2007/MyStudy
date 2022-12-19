### 解题思路
找出差集、共有元素->将arr2的所有共有元素push入res->合并数组

### 代码

```javascript
/**
 * @param {number[]} arr1
 * @param {number[]} arr2
 * @return {number[]}
 */
var relativeSortArray = function(arr1, arr2) {
    let inclu = []
    let sub = []
    let len2 = arr2.length 
    let res = []
    arr1.forEach(item => {
        if(arr2.includes(item)){ // 共有元素
            inclu.push(item);
        }else{
            sub.push(item);  // arr1有arr2没有的(差集)，排序
        }
    });
    for(let i=0; i<len2; i++){
        for(let j=0; j<inclu.length; j++){
            if(arr2[i] == inclu[j]) res.push(inclu[j])
        }
    }
    return res.concat(sub.sort((a,b) => a-b))
};
``` 