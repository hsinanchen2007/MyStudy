### 解题思路
此处撰写解题思路
详细看一下优化吧
![image.png](https://pic.leetcode-cn.com/87dbd73d0f8f6894a37244332f372ab2673d51d097bfbd2ac8b0c68c3fd10c39-image.png)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 * 我的思路：比三数之和多加了 一重循环
 * 双指针
 */
var fourSum = function(nums, target) {
    let lens =nums.length;
    let res =[]; //存放结果
    //数组不存在或者长度小于0
    if(nums ==null || lens<4) return [];
    //数组存在
    //先排序
    nums.sort((a,b)=>a-b);

    // i,j,left,right 分别表示四个数，从小到大排列
    let i,j,left,right;
    let sum =0;
    for(i=0;i<lens-3;i++){  //第一个数
        while(i>0 && nums[i]==nums[i-1]) i++;
        // 添加代码优化-----
        let min =nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
        if(min>target) continue;  //第一层，如果最小值就大于target
        let max =nums[i]+nums[lens-1]+nums[lens-2]+nums[lens-3];
        if(max<target) continue;   //第一层，如果最大值就小于target
        // ---------------
        for(j=i+1;j<lens-2;j++){  //第二个数
        while(j>i+1 && nums[j]==nums[j-1]) j++;
        // 添加代码优化-----
        min =nums[i]+nums[j]+nums[j+1]+nums[j+2];
        if(min>target) continue;  //第二层，如果最小值就大于target
         max =nums[i]+nums[j]+nums[lens-2]+nums[lens-1];
        if(max<target) continue; //第二层，如果最大值就小于target
        // ---------------
            left =j+1;
            right =lens-1;
            while(left<right){
                sum =nums[i]+nums[j]+nums[left]+nums[right];
                if(sum == target){
                    res.push([nums[i],nums[j],nums[left],nums[right]]);
                    left++;
                    while(left<right && nums[left]==nums[left-1]) left++;
                    right--;
                    while(left<right && nums[right]==nums[right+1]) right--;
                }else if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }

        }
    }
    return res;
};
```