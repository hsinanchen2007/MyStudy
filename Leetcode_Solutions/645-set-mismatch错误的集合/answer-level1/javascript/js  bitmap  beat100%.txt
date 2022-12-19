```
var findErrorNums = function(nums) {
    //有一个元素重复  nums是无序的
    //新建一个数组
    var arr = new Array(nums.length).fill(0);
    let res1=0,res2=0;
    for(let i  of nums){
        arr[i-1]++;
        if(arr[i-1]==2) res1=i;
    }
    for(let i=0;i<arr.length;++i){
        if(arr[i]==0){
            return [res1,i+1];
        } 
    }
    return [];
};
```
