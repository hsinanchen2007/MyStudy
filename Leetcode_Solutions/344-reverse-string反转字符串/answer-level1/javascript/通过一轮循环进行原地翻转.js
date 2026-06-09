思路：
把字符串当做一个数组，从中点分为两部分，循环前半部分，将后半部分中和前半部分对称的元素进行交换即可。

代码：

```
var reverseString = function(s) {
  let len = s.length;
  for(let i=0; i< len/2; i++){
    let temp = s[i];
    s[i] = s[len-1-i];
    s[len-1-i] = temp;
  }
};
```
