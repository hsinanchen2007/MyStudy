思路：
1.利用reduce建立对象递归求出数组中每个相同元素的个数；
2.利用for...in...查找1.中返回的对象中元素的对应个数超过 ⌊ n/3 ⌋ 次的元素，添加到数组中即可
```
var majorityElement = function(nums) {
    let a=nums.reduce((pre,cur)=>{
        pre[cur]?pre[cur]++:pre[cur]=1;
        return pre;
    },{});
    let max=[];
    for(let k in a){
        if(a[k]>Math.floor(nums.length/3)){
            max.push(k);
        }
    }
    return max;
};
```

