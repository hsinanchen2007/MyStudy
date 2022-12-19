```javascript []
var reverse = function(x) {
    let N = Math.abs(x)+'';
    let match = N.match(/0+$/);
    let m = match ? match[0] : '';
    if(m.length == N.length){
      return x;
    }
  
    let res = N.slice(0,N.length-m.length).split('').reverse().join('');
    if(x < 0){
      res='-'+res-0;
      return res > Math.pow(-2,31) ? res : 0;
    }else {
      res = res-0;
      return res < Math.pow(2,31)-1 ? res : 0;
    }
};
```
