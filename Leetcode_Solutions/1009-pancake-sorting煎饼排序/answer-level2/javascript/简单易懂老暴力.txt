## 暴力循环
### 耗时
执行用时 :76 ms, 在所有 JavaScript 提交中击败了74.07%的用户
内存消耗 :35.5 MB, 在所有 JavaScript 提交中击败了75.00%的用户
 
### 解题思路
- `3 2 4 1`  我们每次查找一个最大的数，得到下标k，然后翻转前k+1个数，得到：
- `4 2 3 1`  然后我们整体翻转，得到：
- `1 3 2 4`  然后我们去除已经排好的4，因为以后我们的翻转肯定不会翻转到最后一个了，得到
- `1 3 2` 然后我们重复上面4个步骤，直到我们的数组长度为1，1个肯定不用翻了

### 代码如下

```
//获取一个数组最大值的下标
function getMaxIndex(nums){
    let max = 0;
    for(let i=0;i<nums.length;i++){
        if(nums[i]>nums[max]){
            max = i;
        }
    }
    return max;
}

//翻转一个数组的0-index项
function reverseNums(nums,index){
    if(index<1){
        return;
    }
    let i = 0;
    let j = index;
    while(i<j){
        [nums[i],nums[j]] = [nums[j],nums[i]];
        i++;
        j--;
    }
}
var pancakeSort = function(A) {
   let ans = [];
   let max;
   while(A.length>1){
        max = getMaxIndex(A);
        //如果第一个数是最大的，那么只翻转第一个，没什么意义，所以判断max>0
        max>0&&(ans.push(max+1))
        reverseNums(A,max)
        reverseNums(A,A.length-1)
        ans.push(A.length);
        A.pop();
   }
   return ans;
};
```