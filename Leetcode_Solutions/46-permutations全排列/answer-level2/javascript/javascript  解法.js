```
var permute = function(nums) {
    let temp=[],used=[],depth=0,result=[];
    backTrack(nums,used,result,temp,depth)
    return result;
};
function backTrack(nums,used,result,temp,depth){
    if(depth==nums.length){
        result.push(temp);
        return  ;
    }
    for(var i=0;i<nums.length;i++){
        if(!used[i]){
            used[i]=true;
            temp.push(nums[i]);
            arguments.callee(nums,used,result,[...temp],depth+1)
            used[i]=false;
            temp.pop();
        }
    }
}
```
