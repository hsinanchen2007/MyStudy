### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
// 更容易想到的： 排序 + 遍历
// 利用Js数组原生的sort排序，因为sort是原地算法，所以空间复杂度是O(1)，时间复杂度O(nlogn);
// 遍历，因为是排序好的，所以必然会存在num[a] === nums[a + 1]的情况，时间复杂度O(n)；
// 时间和空间，都满足；
var findDuplicateWithSort = function(nums) {
  nums.sort((a, b) => a - b);
  const length = nums.length - 1;
  for(let i=0; i<length; i++){
    if(nums[i] === nums[i + 1]){
      return nums[i];
    }
  }
};


// 一种非常非常巧妙的方法，居然才击败了90%的用户，我不信, 我要再跑一遍;
// 空间复杂度O(1)，时间复杂度O(n);
// 由于给定nums[n + 1]的数组, 数的范围是 {1, n};
// 所以采用了用数组的值去算索引，并将对应索引的值标记；那么相同的值，计算出来的索引就会相同
// 如果计算出来的索引已经被标记，那么就说明前面有相同的数；
// 标记的方式很重要，JS中，你可以去取反，可以加一个字符，其要求就是要可逆；比如
// 增加字符a: parseInt(nums[a] + 'a') = nums[a];
// 取反： Math.abs(-nums[i]) = nums[i];
// 关键就在标记的可逆，这样标记才不会覆盖原来的数，而只是会增加一次数的转换，但这样并不增加时间和空间复杂度
var findDuplicate = function(nums) {
  const length = nums.length;
  for(let i=0; i<length; i++){
    const index = Math.abs(nums[i]);
    if(nums[index - 1] < 0){
      return index;
    } else {
      nums[index - 1] = -nums[index - 1];
    }
  }
};
```