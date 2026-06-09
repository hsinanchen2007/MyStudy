*法一：暴力双循环*

```js
var numJewelsInStones = function(J, S) {
    let count = 0;
    for(let i = 0; i < S.length; i++) {
        let index = i;
        for(let j = 0; j < J.length; j++) {
          if (S[i] === J[j]) {
              count++;
              i--;
              S = S.slice(0, index) + S.slice(index+1, S.length)
          }
        }
    }
    return count
};
```

*法二：正则*

```js
var numJewelsInStones2 = function(J, S) {
    let len = S.length;
    for(let i = 0; i < J.length; i++) {
        let pat = new RegExp(J[i], 'g');
        S = S.replace(pat, '')
    }
    return len - S.length;
};
```

*法三：正则*

```js
var numJewelsInStones = function(J, S) {
    let len = S.length;
    let SS = '[' + J + ']';
    let pat = new RegExp(SS, 'g');
    S = S.replace(pat, '')
    return len - S.length;
};
```

*法四：数组 filter() 方法*

```js
var numJewelsInStones = function(J, S) {
    let jArr = J.split('');
    let sArr = S.split('');
    let JS = sArr.filter((item) => {
        return jArr.includes(item)
    })
    return JS.length
};
```

*法五：借助Set数据集*

```js
var numJewelsInStones = function(J, S) {
    let set = new Set(J.split(''));
    let count = 0;
    for (let item of S) {
      if(set.has(item)) {
        count++
      }
    }
    return count
};
```

