### 解题思路
首先sort，O(nlogn);

回溯法，每次压入一个x，比较x和currentTarget
如果x < currentTarget
更新currentTarget，把当前路径压入curArr,然后进行递归
如果x === currentTarget
则把当前curArr压入最后的resultArr，
如果x > currentTarget
则不做处理

并且可以提前判断，如果currentTarget < 0
则提前终止进行剪枝,直接return，之后的也不再查询
![image.png](https://pic.leetcode-cn.com/95160c17f6cac27eaf080f5734de3062762e553a5539dc1b431469f6927ca849-image.png)

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
let result;
let curArr;
var combinationSum = function(candidates, target) {
    if(target < 0 || !candidates || candidates.length === 0){
        return;
    }
    result = new Array();
    curArr = new Array();
    let sortArr = candidates.sort(sortFn);
    console.log(sortArr);
    recall(sortArr,0,target,curArr);
    return result;
};
let recall = function(nums,beginIndex,currentTarget,curArr){
    if(currentTarget < 0){
        return ;
    }
    for(let i = beginIndex; i < nums.length;i++){
        let x = nums[i];
        curArr.push(x);
        if(x < currentTarget){
            recall(nums,i,(currentTarget-x),curArr);
        }else if(x === currentTarget){
            result.push([].concat(curArr));
        }else{
            curArr.pop();
            return;
        }
        curArr.pop();
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