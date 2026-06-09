### 解题思路
这道题与之前的那道题相比主要有两个区别
1.不能重复选择一个元素
2.可能存在重复的元素

针对第一个问题，不能重复选择，只需要在进入下一层时，把index+1即可
针对第二个问题，我们需要对重复元素访问的元素进行剪枝
我们可以保存一个lastOne元素表示上一个访问的元素，
如果当前元素与上一个元素相等 && 当前元素等于lastOne
则表明之前的元素已经被访问过了，这样我们就进行剪枝

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
let result;
let curArr;
var combinationSum2 = function(candidates, target) {
    if(target < 0 || !candidates || candidates.length === 0){
        return;
    }
    result = new Array();
    curArr = new Array();
    let sortArr = candidates.sort(sortFn);
    recall(sortArr,0,target,curArr);
    return result;
};
let recall = function(nums,beginIndex,currentTarget,curArr){
    if(currentTarget < 0){
        return ;
    }
    // let visit = new Array(nums.length).fill(false);
    let last = null;
    for(let i = beginIndex; i < nums.length;i++){
        if(i > 0 && nums[i] === nums[i-1] && last === nums[i]){
            // visit[i] = true;
            continue;
        }
        let x = nums[i];
        curArr.push(x);
        if(x < currentTarget){
            recall(nums,i+1,(currentTarget-x),curArr);
        }else if(x === currentTarget){
            result.push([].concat(curArr));
        }else{
            curArr.pop();
            return;
        }
        curArr.pop();
        last = x;
        // visit[i] = true
    }
}
let sortFn = function(a , b){
    if(a < b){
      return -1;
    }
    else if (a > b) {
      return 1;
    }
    else{
     return 0;
   }
}

```