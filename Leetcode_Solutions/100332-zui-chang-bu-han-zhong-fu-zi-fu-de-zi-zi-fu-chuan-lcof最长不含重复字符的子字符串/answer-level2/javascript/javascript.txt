```
var lengthOfLongestSubstring = function(s) {
  let arr=s.split('');
  let len=0;
  let res=[];
  for(let i=0;i<arr.length;i++){
    if(res.includes(arr[i])){
      res.splice(res.indexOf(arr[i]),res.length);
    }
    res.unshift(arr[i]);
    len=Math.max(len,res.length);
  }
  return len
};
```
