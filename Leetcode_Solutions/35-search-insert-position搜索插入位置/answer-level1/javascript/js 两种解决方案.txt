1、第一种
```
var searchInsert = function(nums, target) {
    const index=nums.indexOf(target)
    if(index>-1){
        return index
    }else{
        nums.push(target)
        nums.sort(function(a,b){
            return a-b   
        })
        return nums.indexOf(target)
    }
};
```
1、第二种
```
var searchInsert = function(nums, target) {
    let map=new Map()
    let index
    nums.map((v,i)=>{
        v===target?index=i:""
    })
    if(index){
        return index 
    }else{
        nums.push(target)
        nums.sort(function(a,b){
            return a-b   
        })
        return nums.indexOf(target)
    }
}; 
//还有一种相似的
var searchInsert = function(nums, target) {
    for(let i=0;i<nums.length;i++){
        if(nums[i]===target){
            return i
        }
    }
    nums.push(target)
    nums.sort(function(a,b){
        return a-b   
    })
    return nums.indexOf(target)
};
```

