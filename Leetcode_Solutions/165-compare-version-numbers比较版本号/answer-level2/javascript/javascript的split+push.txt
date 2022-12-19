首先以'.'为分隔符分割，然后使两个数组的长度相等（在短的数组后面push 0直到两个数组相等）
然后按照题意比较
```
/**
 * @param {string} version1
 * @param {string} version2
 * @return {number}
 */
var compareVersion = function(version1, version2) {
  let arr1=version1.split('.');
  let arr2=version2.split('.');
  let length=Math.max(arr1.length,arr2.length);
  while(arr1.length!==length){
    arr1.push(0)
  }
  while(arr2.length!==length){
    arr2.push(0)
  }
  for(let i=0;i<length;i++){
    if(parseInt(arr1[i])<parseInt(arr2[i])){
      return -1
    }
    if(parseInt(arr1[i])>parseInt(arr2[i])){
      return 1
    }
  }
  return 0
};
```
