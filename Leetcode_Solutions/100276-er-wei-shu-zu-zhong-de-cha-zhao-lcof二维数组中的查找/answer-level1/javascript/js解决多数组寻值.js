### 解题思路
思路，数组降维：这里用了一个类似迭代的方式去做，判断是否为数组，是的话继续遍历，直到个体不为数组就可以放到定义的变量中
再通过 filter去匹配，filter可以将返回值为true的元素放到新的数组里
下面是第二种降维的方法： 用pop函数将数组每一部分剔除出来，再判断是否为数组，是就用扩展符解开一层后继续加入原数组中，直到全部解开。这里注意，最后的数组会逆序，所以需要调转过来

### 代码
var findNumberIn2DArray = function(matrix, target) {
    let ret = [];
    let b = function(arr) {
        arr.forEach(function(item){
          item instanceof Array ?  b(item) : ret.push(item);
        });
    }
    b(matrix);
    let m = ret.filter(item => item==target);
    return m.length == 0? false:true;
}

// var findNumberIn2DArray = function(matrix, target) {
//       let a= [...matrix];
//       let arr = [];
//       while(a.length){
//       const b = a.pop();
//       if(Array.isArray(b)){
//           a.push(...b);
//       } else {
//          arr.push(b);
//       }
//       }
//      let mat = arr.reverse();
//      let s = mat.filter(item => item==target);
//      return s.length==0 ? false : true;
// };

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

```