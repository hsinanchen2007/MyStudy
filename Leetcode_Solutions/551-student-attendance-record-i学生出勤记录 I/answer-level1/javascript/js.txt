1.是否有连续3个L
2.是否有2个A
```
    const A = s.match(new RegExp('A', 'g')) === null ? 'true==' : s.match(new RegExp('A', 'g')).length <=1
    const L = s.match(new RegExp('LLL', 'g')) === null
```

循环

```
    let a = 0
    let l = 0
   for (let i = 0; i < s.length; i++) {
      if(s[i] === 'A'){
        a++
      } else if(s[i] === 'L' && s[i+1] === 'L' &&  s[i+2] === 'L'){
        l = 5
        break
      }

    }
    return a<=1 && l<=2
```
