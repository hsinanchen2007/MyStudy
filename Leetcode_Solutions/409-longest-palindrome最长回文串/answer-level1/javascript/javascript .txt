先排序，如果后面的数和前面的的一样count++，然后将其切割掉；如果不一样i++;
最后count如果正好是字符串长度的一半，表示没有字符可以做回文最中间独一无二的值。
```
var longestPalindrome = function(s) {
  let arr=s.split('').sort();
  let count=0;
  for(let i=1;i<arr.length;){
    if(arr[i]==arr[i-1]){    
      count++;
      arr.splice(i-1,2)      
    }else{
      i++;
    }
  }
  return s.length===count*2?count*2:count*2+1
};
```
