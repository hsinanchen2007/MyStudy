![image.png](https://pic.leetcode-cn.com/d9da6c61e90903b9ff3e7dca8df81fa723d144032a092947d6354ff1a90e82b7-image.png)
成绩最好的一次,感觉这个数据没什么用,提交多次,差别还挺大.
减值迭代循环,从最后一位加起,只要不超过10,就意味着不用再继续遍历了,直接return,走到后面,意味着一直加到头了还是超过10,那就直接concat一个1(没有用unshift的原因是对比了一下concat性能较好),完成!

```
var plusOne = function(digits) {
  for(let i=digits.length-1;i>=0;i--){
    digits[i]++;
    digits[i]%=10;
    if(digits[i]!==0){
      return digits;
    }
  }
  return [1].concat(digits);
};
```
