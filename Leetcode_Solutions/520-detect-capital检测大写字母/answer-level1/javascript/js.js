1.全部为大写或小写
2.如果 第一位是大写，第二位一定是小写```
代码块

```
var word = "ffffffffffffffffffffF"

    if(word === word.toLowerCase() || word === word.toUpperCase()) {
      return true
    } else {
      if(/[A-Z]/.test(word[0])){
        // 第一个是大写字母
        let m = word.substring(1,word.length)

        if(m === m.toLowerCase()) {
          return true
        } else {
          return false
        }
      }
      return false
    }

```

