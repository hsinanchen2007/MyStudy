因为这道题的返回值是数组，Set和数组比较好转换，所以用Set。

之前经常用for循环一头遍历，for(let i of arr){}这种，想着能不能优化一下，以我这脑力，暂时只能想到两头遍历，
定义一个i=0，j=nums.length-1,每次循环体里就校验两个数，判断set里有没有这个数，有的话就删掉，没有的话就加上，
因为除了要返回的数都是出现两次，所以set最后只会返回我们要的结果，然后直接return [...set].reverse(),
因为你是两头遍历，所以set保存的顺序要颠倒一下


```
var singleNumbers = function(nums) {
    let set = new  Set();
    let i = 0,j = nums.length - 1;
    while(i < j) {
        set.has(nums[i]) ? set.delete(nums[i]) : set.add(nums[i]);
        set.has(nums[j]) ? set.delete(nums[j]) : set.add(nums[j]);
        i++;
        j--;
    }
    return [...set].reverse();
};
```
