### 解题思路
看代码

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isStraight = function(nums) {
    //从小到大排序
    const minSort = nums.sort((a,b)=> a-b);
    //记录每个数字之间大差值，反正不能大于4
    let sum = 0;
    //不能超过4
    for(let i = 0; i<4;i++){
        //忽略0也就是王
        if(minSort[i] == 0){
            continue
        }
        //如果扑克牌（非0）重复，说明不是顺子
        else if(nums[i] == nums[i+1]){
            return false
        }else{
            //差值记录
            sum = sum + nums[i+1] - nums[i]
        }
    }
    //如果超过4，说明不是顺子。
    return sum<5
};
```