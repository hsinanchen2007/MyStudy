```
var topKFrequent = function(nums, k) {
    //前k个高频元素
    let hash = new Map();
        //频率统计
    for(let i of nums){
        if(!hash.has(i)) hash.set(i,1);
        else hash.set(i,hash.get(i)+1);
    }
    nums=new Array(hash.size);
    let j=0;
    for(let [key,value] of hash){
        nums[j++]=[key,value];
    }
    getK(nums,0,nums.length-1,k);
    let res=new Array(k);
    for(let i=0;i<k;++i){
        res[i] = nums[i][0];
    }
    return res;
};

//分治   
var getK = function(nums,left,right,k){
    if(left>=right) return ;
    let temp = quikSort(nums,left,right,k);
    if(temp+1==k+left) return ;
    else if(temp+1<k+left){
        getK(nums,temp+1,right,k-(temp+1-left));  //前面的temp+1-left已经符合要求 找剩下的k-(temp+1-left)个最大元素
    } else getK(nums,left,temp-1,k);      //继续找前k个最大元素
    return ;
}

var quikSort = function(nums,left,right){
    if(left>=right) return left;
    let pivot = nums[left];
    let i=left,j=right;
    while(i<j){
        while(nums[j][1]<pivot[1] && i<j) --j;
        nums[i] = nums[j];
        while(nums[i][1]>=pivot[1] && i<j) ++i;
        nums[j] = nums[i];
        if(i==j) nums[i] = pivot;
    }
    return i;
}
```
