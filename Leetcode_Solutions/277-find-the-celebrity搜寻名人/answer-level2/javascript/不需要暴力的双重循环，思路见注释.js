### 解题思路
不需要暴力的双重循环，思路见注释

### 代码

```javascript
/**
 * Definition for knows()
 * 
 * @param {integer} person a
 * @param {integer} person b
 * @return {boolean} whether a knows b
 * knows = function(a, b) {
 *     ...
 * };
 */

/**
 * @param {function} knows()
 * @return {function}
 */
var solution = function(knows) {
    /**
     * @param {integer} n Total people
     * @return {integer} The celebrity
     */
    return function(n) {
        // 根据题意，可以分解为人群中如果存在名人的话，就得出，所有人都认识他，而他一个人都不认识
        // 1：所有人都认识他 ==> 其它n-1节点的入度至少为 1
        // 2：他一个人都不认识 ==> 节点出度为 0
        let index = 0; // 假设index是名人
        // 先找出 出度为0 的节点：一个人都不认识的人
        for(let i=0;i<n;i++){
            // 如果存在认识的人，则判断下一个
            if(knows(index,i))index=i;
        }

        for(let i=0;i<n;i++){
            if(index === i)continue;
            // 在判断 index 是否存在别人不认识他，或者他认识别人，如果存在则不是名人
            if(knows(index,i)||!knows(i,index))return -1;
        }
        return index;
    };
};
```