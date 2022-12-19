# 双指针
本题其实骨子里的逻辑与三数之和是相同的，其实可以更加普适的理解俩数以上求和的减去一层循环的方式就是双指针
通过循环固定n-2个值，然后一层循环里双指针，牺牲一定的空间换取一层循环的时间~
```
var threeSumClosest = function(nums, target) {
    nums.sort((a,b)=>a-b);
    let result = nums[0]+nums[1]+nums[2];
    for(let i = 0,len = nums.length;i<len;i++){
        let start = i+1,end = len-1;
        while(end > start){
            let sum = nums[start]+nums[i]+nums[end]
            if(Math.abs(target - sum) < Math.abs(target - result)){
                result = sum;
            }
            if(sum > target){
               end--;
            }else if(sum < target){
                start++;
            }else{
                return result;
            }       
        }
    }
    return result;
};
```
