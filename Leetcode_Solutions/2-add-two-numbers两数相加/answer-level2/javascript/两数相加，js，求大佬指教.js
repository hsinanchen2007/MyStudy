```javascript []
var addTwoNumbers = function(l1, l2) {
    var res = new Array(),n1 = 0,n2 = 0,sum;
    for(var i = 0;i<l1.length;i++){
        n1 = n1+l1[i]*Math.pow(10,i);
    }
    for( i = 0;i<l2.length;i++){
        n2 = n2+l2[i]*Math.pow(10,i);
    }
    sum =n1+n2;
    do{
        res.push(sum%10);
        sum = Math.floor(sum/10);
    }while(sum!=0);
    return res;
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```

这个js代码在浏览器上能正确输出，但为什么在leetcode上是输出undefined呀！有大佬能解释下吗？