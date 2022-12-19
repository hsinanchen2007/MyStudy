```
var day = 1,month = 9,year = 2019
var c = new Date(year, month-1, day)
console.log('题目时间', c)
console.log('星期',c.getDay())
switch(c.getDay()){
     case 0:
        console.log('Sunday')
        break
     case 1:
        console.log('Monday')
        break
     case 2:
        console.log('Tuesday')
        break
     case 3:
        console.log('Wednesday')
        break
    case 4:
        console.log('Thursday')
        break
    case 5:
        console.log('Friday')
        break
    case 6:
        console.log('Saturday')
        break                                             
}
```
API，别打，脸。嘿嘿嘿。
执行用时 :64 ms, 在所有 javascript 提交中击败了83.45%的用户
内存消耗 :33.9 MB, 在所有 javascript 提交中击败了100.00%的用户