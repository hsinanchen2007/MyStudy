一共想出三种解法，这个题的核心部分不是获取三个数和为0可能得结果数组，而是如何实现高效地结果去重，去重算法的实现影响你是否能提交成功。大部分都卡在了超时这个问题上，包括我刚开始也是，后面优化了去重之后其中两种方法才提交成功，所以这个题通过率奇低无比。

**暴力三层循环**
在某个测试用例会超时，本来时间复杂度就是O(n^3)，还要去重，效率奇低无比，代码略。

**两层循环+Map**
三层循环的优化版而已，把最后一个层的循环换成Map以便快速查找，时间复杂度降为O(n^2)，实现起来也很简单，去重的部分优化之后成功通过，因为效率一般，代码略。

**排序双指针** 
速度还不错的解法，逻辑清晰明了，大部分时间都在解决去重的问题，处理的各种特殊的test case了，细节部分代码里有注释。
- 排序
- 双指针
- 去重
```
var threeSum = function(nums) {
    if(nums.length < 3) return [];
    nums.sort((a, b) => a-b);
    let length = nums.length;
    let result = [];
    if(nums[0] <= 0 && nums[length-1] >= 0){
        for(let i=0; i<length-2; i++){
            if(i>0 && nums[i] === nums[i-1]) continue; //Ingnore the dupliate number after the first number.
            let l=i+1; //Left pointer
            let r = length-1; //Right pointer
            
            while(l<r){
                let sum = nums[i] + nums[l] + nums[r];
                if(sum>0){ 
                    r--;  //Right pointer move to left
                }else if(sum<0){
                    l++; //Left pointer move to right
                }else{
                    result.push([nums[i], nums[l], nums[r]]);
                    while(l<r && nums[l] === nums[l+1]){
                        l++; //Ignore the duplicate number
                    }
                    while(l<r && nums[r] === nums[r-1]){
                        r--; //Ignore the duplicate number   
                    }
                    r--;
                    l++;
                }                  
            }

        }    
    }
    return result;
};
```
