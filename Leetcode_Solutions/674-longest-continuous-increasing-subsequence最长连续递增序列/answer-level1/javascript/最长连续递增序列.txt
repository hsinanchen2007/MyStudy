/**
 * @param {number[]} nums
 * @return {number}
 */
var findLengthOfLCIS = function(arr) {
  if(arr.length==0) return 0
  let count = 1;
  let ans = 1;
  for(let i=0;i<arr.length;i++){
    if(arr[i+1]>arr[i]){
      count++
    }else{
      count =1;//一旦发现比上一个数小的，重新赋值
    }
    ans = Math.max(count,ans)  //保存最大的连续递增的数量
  }
  return ans         
};