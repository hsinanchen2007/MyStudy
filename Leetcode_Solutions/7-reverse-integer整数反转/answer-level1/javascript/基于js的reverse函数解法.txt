```javascript []
    var reverse = function(x) {
      const flag = x > 0 ? '' : '-';
      const str = String(x);
      const arr = str.split('');
      arr.reverse();
      const result = parseInt(`${flag}${arr.join('')}`);
      if (result <= -Math.pow(2, 31) || result >= Math.pow(2, 31)) return 0;
      return result;
    };
```
不知道我这种算不算投机取巧