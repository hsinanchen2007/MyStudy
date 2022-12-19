//第一种：暴力法：复杂度太高
```
let res = nums[0]+nums[1]+nums[2];
let abs = Math.abs(res-target);
for(let i=0; i<nums.length-2;i++){
    for(let j=i+1; j<nums.length-1;j++){
        for(let k=j+1; k<nums.length;k++){
            let temp = nums[i]+nums[j]+nums[k];
            if(Math.abs(temp-target) < abs){
                res = temp;
                abs = Math.abs(temp-target);
            }
        }
    }
}
return res;
```
第二种方法
    
```
nums.sort((a,b) => a-b); // 先排序
let res = nums[0]+nums[1]+nums[2];
let abs = Math.abs(res-target);
for(let i=0; i<nums.length-2;i++){
    let start = i+1;
    let end = nums.length-1;
    while(start < end){
        let temp = nums[i]+nums[start]+nums[end];
        if(Math.abs(temp - target) < abs){
            res = temp;
            abs = Math.abs(temp - target)
        } 
        if(temp < target){
            start++;
        }else if(temp > target){
            end--;
        }else{
            return temp; // 若temp=target，直接输出结果
        }
    }
}
return res;
```