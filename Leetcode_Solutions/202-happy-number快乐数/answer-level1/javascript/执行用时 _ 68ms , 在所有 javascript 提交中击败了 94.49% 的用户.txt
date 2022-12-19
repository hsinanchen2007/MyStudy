快乐，简单就完了
```
    var isHappy = function (n) {
        if (n == 1 || n == 7) return true;
        if (n < 9) return false;
        let t = ('' + n).split('');
        let k = 0;

        t.forEach(t => {
            k += Math.pow(t, 2);
        });

        return k == 1 ? true : isHappy(k);
    };
```
