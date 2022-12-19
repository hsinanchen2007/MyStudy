### 解题思路

```
如:widths = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10],
S = "abcdefghijklmnopqrstuvwxyz"

先创建个对象obj来存放 a-z 所对应的数

 此时 obj = {"a":10,"b":10,"c":10,"d":10,"e":10,"f":10,"g":10,"h":10,"i":10,"j":10,"k":10,"l":10,"m":10,"n":10,"o":10,"p":10,"q":10,"r":10,"s":10,"t":10,"u":10,"v":10,"w":10,"x":10,"y":10,"z":10} 

然后循环字符串S, 把字母换成值,放到一个数组list中

此时 S = "abcdefghijklmnopqrstuvwxyz" 就变成了 
     list = [10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10]

这时就该遍历 list了, 再建个数组arr 和 num 用来存放 结果 和 计数

把list 逐项累加 加够100, 就往arr 添加 一项, 一次类推

当然有特殊情况, 当相加 要大于 100 时, 就把前面累加的数push到 arr中, 把num重新赋值为 当前项数值, 然后继续

当如果是最后一项,且相加 要大于一百, 则直接往arr中push之前的num后,在push当前项.
```


### 代码

```javascript
/**
 * @param {number[]} widths
 * @param {string} S
 * @return {number[]}
 */
var numberOfLines = function(widths, S) {
  let obj = {}
  widths.forEach((item,index) => {
    let letter = String.fromCharCode(index + 97);
    obj[letter] = item
  })
  let list = []
  for(let prop of S){
    list.push(obj[prop])
  }
  let arr = [],num = 0
  list.forEach((t,i)=> {
    if(num < 100 && (num + t <= 100) && i < list.length -1){
      num += t
    } else if (i < list.length -1) {
      arr.push(num)
      num = t
    } else if(num + t > 100){
      arr.push(num)
      arr.push(t)
    } else {
      num += t
      arr.push(num)
    }
  })
  return [arr.length,arr[arr.length-1]]
};
```


哈哈, 看着字母的就忍不住想用对象来, 想复杂了

其实, widths 是按照 a-z 固定排序的, 那么就可以通过S中字母推算出 字母对应 widths 的 索引, 就可以直接得出S字母对应的数值了

累加也不用想这么复杂, 满足大于100的直接,行数直接加1, 然后累计数重新赋值

```
如:widths = [4,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10],
S = "bbbcccdddaaa"

换成数字就是 S= "10 10 10 10 10 10 10 10 10 4 4 4"

小写字母 a 转成ASCII码 是 97, z 为 122, 所以 a-z 的索引可以用 字母的ASCII码 减去 97 得到

弄个变量line记录行数,total记录累加数, 然后循环S,

 当大于100时, total = 102, 已经遍历到最后的 a 了, 这时line 加 1, total重新赋值为 4

结束循环时, line = 2, total = 4
    
```


```js
var numberOfLines = function(widths, S) {
  let line= 1,total = 0
  for(let prop of S){
    let num = widths[prop.charCodeAt() - 97]
    total += num
    if(total > 100){
      line++
      total = num
    }
  }
  return [line,total]
};
```
