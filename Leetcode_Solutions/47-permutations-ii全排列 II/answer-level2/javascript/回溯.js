
和上一题类似，核心在于去除重复。首先要排序，每次回溯完，添新枝时候要判断arr是否和上次一样。

```
var permuteUnique = function(nums) {
  const state = [];
  const res = [];
  const used = {};
  
  nums.sort((a,b) =>{
    return a-b;
  })
  
  function recursive(pos) {
    if (pos === nums.length) {
      const newS = [...state];
      res.push(newS);
      return;
    }
    let arr;
    for(let i=0; i< nums.length; i++) {
      if (!used[i]){
        used[i] = true;
          state.push(nums[i]);
          if (JSON.stringify(arr) !== JSON.stringify(state)){
            arr = [...state];
            recursive(pos+1);
          }
          state.pop();
        used[i] = false;
      }
    }
  }

  recursive(0);
  return res;
};
```
