用数组储存最后的结果，然后输出成字符串
讲进制转换写成函数方便负数和正数两种情况调用

```
var convertToBase7 = function(num) {
   let res=[];
   if(num>=0) return go(num)
   if(num<=0) return '-'+go(Math.abs(num))
   
   function go(num){
     while(num>=7){
     res.unshift(num%7);
     num=Math.floor(num/7)
   }
   res.unshift(num)
   return res.join('')
   } 
};
```
