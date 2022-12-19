
```javascript []
var reverseWords = function(s) {
   let arr = []
   s.split(/\s/).forEach(val => {
     arr.push(
       val.split('').reverse().join('')
     )
   })
   return arr.join(' ')
}
```