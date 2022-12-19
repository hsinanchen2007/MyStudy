```
var isHappy = function(n) {
  var mySet=new Set();
  while(1){
    var k=n,sum=0;
    while(k){
      sum+=Math.pow(k%10,2);
      k=Math.floor(k/10);
    }
    if(sum==1){
      return true;
    }
    else if(!mySet.has(sum)){
      mySet.add(sum);
      n=sum;
    }
    else{
      return false;
    }
  }
};
```

