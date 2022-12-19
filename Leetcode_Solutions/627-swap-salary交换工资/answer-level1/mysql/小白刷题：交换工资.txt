类似不借用中间变量交换两数值

代码：
```
update salary set sex = char(ascii('m') + ascii('f') - ascii(sex))
```
