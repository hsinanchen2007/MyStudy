直接用new Date生成当天日期，获取当前是第几天就可以啦。
```
let date = new Date(`${year}-${month}-${date}`);
date.getDay();
```
