
复制一份数组进行升序排序，记录每个数字排序后第一次出现的下标位置

由于排序后前面的数字都更小，该下标就是小于当前数字的数字数量

时间复杂度：O(nlogn) 排序  
空间复杂度：O(n) 额外复制的一份数组copy和哈希表obj

```js
var smallerNumbersThanCurrent = function(nums) {
  let copy = [].concat(nums)
  copy.sort((a,b)=>{return a-b});
  let obj={};
  for(let i=0;i<copy.length;i++){
    if(obj[copy[i]]===undefined){
      obj[copy[i]] = i;
    }
  }
  // console.log(copy);
  let res = [];
  for(let num of nums){
    res.push(obj[num]);
  }
  return res;
};

```