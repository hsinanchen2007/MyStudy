*法一*

缺点：速度太慢

```js
var isLongPressedName = function(name, typed) {
    for (let i = 0; i < typed.length; i++) {
        if (typed[i] !== name[i]) {
          typed = typed.substr(0,i) + typed.substr(i+1)
          i--
        }
    }
    return typed === name
};
```

*法二：双指针*

推荐

```js
var isLongPressedName = function(name, typed) {
    let i = 0
    let j = 0
    while(name[i] && typed[j]) {
      if (name[i] === typed[j]) {
        i++
        j++
      } else {
        j++
      }
    }
    return i === name.length
};
```

