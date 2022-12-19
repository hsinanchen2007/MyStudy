### 解题思路
这题居然是中等难度，我震惊了

这比我今天做的简单难度还简单=。=

两个指针，差值为一右指针就前进一格，差值大于一就推一个区间进数组，然后左右指针同时指向下一个值继续遍历

注意一下只有一个值得情况就ok了

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function(nums) {
    var left,right;
    var tmp="->";
    var arr=[];
    left=nums[0];
    right=nums[0];
    if (nums.length===1){
        arr.push(nums[0]+"")
        return arr
    }
    for (let i=1;i<=nums.length;i++){
        if (nums[i]-nums[i-1]===1){
            right=nums[i]
        }
        else if(left===right){
            arr.push(left+"")
            left=nums[i]
            right=nums[i]
        }
        else {
            arr.push(left+tmp+right)
            left=nums[i]
            right=nums[i]
        }
    }
    return arr
};
```