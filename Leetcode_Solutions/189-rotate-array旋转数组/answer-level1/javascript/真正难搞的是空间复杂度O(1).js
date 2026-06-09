用额外数组很简单,不用就得考虑很多
```
var rotate = function(nums, k) {
    k%=nums.length;
    let pre=nums[0];
    let count=0;
    let start=0;
    for(let i=0;count<nums.length;i+=k){
        let temp=nums[(i+k)%nums.length];
        nums[(i+k)%nums.length]=pre;
        pre=temp;
        count++;
        if(((i+k)%nums.length)==start){
            i++;
            start++;
            pre=nums[start];
        }
    }
};
```
