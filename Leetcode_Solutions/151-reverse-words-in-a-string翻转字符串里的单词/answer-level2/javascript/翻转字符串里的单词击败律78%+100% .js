*新人报道，如有问题望指正！！*
# 1.初步规划
- 字符串去空格
- 字符串分割成数组
- 数组反转
- 遍历数组去重
- join组合

# 2.遇到问题并修改
- 内部会有多个空格 也会被分割后 放入数组即会多出很多空字符串元素
- 若正向循环使用splice会时循环下标错乱，因此使用反向循环避免问题
**解决方法：**
  1. 加入判断条件去空字串
  2. 使用反向循环避免问题
```
var reverseWords = function(s) {
  var arr = s.trim().split(" ")
  arr.reverse()
  for(var i=arr.length-1;i>=0;i--){
    arr[i]=arr[i].trim()
    if(arr[i].length==0)
      arr.splice(i, 1);
  }
  return arr.join(" ")
}
```
