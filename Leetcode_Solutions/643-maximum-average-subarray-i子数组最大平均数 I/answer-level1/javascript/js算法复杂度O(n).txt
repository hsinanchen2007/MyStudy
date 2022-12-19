先求最大的子数组和

```javascript []
var findMaxAverage = function(nums, k) {
  let max=0,sum=0;
  for(let i = 0; i<k&&i<nums.length;i++){
    sum+=nums[i];
  }
  max=sum;
  for(let i=k;i<nums.length;i++){
    sum= sum+nums[i]-nums[i-k];
    if(sum>max){
      max = sum;
    }
  }
  return max/k;
};
```

