### 解
为了练习一下forEach。。。但是有点慢，不知道为何，求解答

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
let numsA = nums;
let numsB = nums;
let numsC = [];
   numsA.forEach(function(val,id) {
                    numsB.forEach(function(val2,id2){
                        if(val==(target-Number(val2))){
                            if(numsC.indexOf(id)<0&&id!==id2) {
                                 numsC.push(id); 
                                 numsC.push(id2);
                            }

                           
                           
                        }
                    })
                });
                return numsC;
};
```