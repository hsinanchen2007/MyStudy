*法一*

```js
var rotatedDigits = function(N) {
    let goodNum = '2569';
    let count = 0;
    for(let i = 1; i <= N; i++) {
        let str = i.toString();
        if (str.indexOf('3') >= 0 || str.indexOf('4') >= 0 || str.indexOf('7') >= 0) {
            continue
        }
        for (let j = 0; j < str.length; j++) {
            if (goodNum.indexOf(str[[j]]) !== -1) {
                count++
                break
            }
        }
    }
    return count
};
```

*法二：正则*

```js
var rotatedDigits = function(N) {
    // 检测N是否含有3、4、7这三个数中的任意一个
    let pat1 = /[347]+/;
    // 检测N是否全部为0、1、8这三个数组成
    let pat2 = /^[018]+$/;
    let count1 = 0;
    let count2 = 0;
    for(let i = 1; i <= N; i++) {
        if (pat1.test(i)) {
        	count1++;
        }
        if (pat2.test(i)) {
        	count2++
        }
    }
    return N - count1 - count2
};
```