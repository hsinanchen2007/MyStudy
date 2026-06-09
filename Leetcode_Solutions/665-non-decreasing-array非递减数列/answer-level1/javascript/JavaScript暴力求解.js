### 解题思路
* 数组有特点，如果长度在1,2这种可以直接提前判断；
* 通过count来检测是否为true，如果count的数值越小，为0即为 false；
* 

### 代码

```javascript
  /**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    let len = nums.length
    let count = 1
    if(len === 1) return true
    if(nums[0] > nums[1]){
        count = 0
    }
    for( let i = 2; i < len; i++){
        if(nums[i]< nums[i-1]){
            if(!count){
                return false
            }
            count--;
        //这里的赋值，把nums[i-1]重新赋值给nums[i]，而不是单纯的赋值为1，保持后续的非递减序列的顺序；
            if(nums[i] < nums[i-2]){
                nums[i]  = nums[i-1]
            }
        }
    }
    return true
};
```