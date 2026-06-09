仓促之作，有待优化~
```
var isPossibleDivide = function(nums, k) {
    let len = nums.length;
    if(len%k != 0) return false;
    nums.sort((a,b)=>a-b);
    let index = 0;
    for(let j = 0;j<len;j++){
        if(typeof nums[j] == "number"){
              let arr = [nums[j]]
              for(let i = 1;i<k;i++){
                  let next = nums.indexOf(arr[i-1]+1);
                  if(next != -1){
                     arr.push(nums[next]);
                     delete nums[next];
                  }else{
                      return false;
                  }
              }
              console.log(arr)
        }
    }
    return true;
};
```
