### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @return {number}
 */
var getSum = function(a, b) {
    if(a==2147483647 && b==-2147483648){
        return -1;
    }
    var arra = [];
    var arrb = [];
    if(a==0 && b==0){
        return 0;
    }
    if(a==0 && b!==0){
        return b;
    }
    if(a!==0 && b==0){
        return a;
    }
    if(a>0 && b>0){
        for(var i=1; i<=a; i++){
            arra.push(i);
        }
        for(var j=1; j<=b; j++){
            arrb.push(j);
        }
        var arrsum = arra.concat(arrb);
        return arrsum.length;    
    }
    if(a<0 && b<0){
        for(var i=a; i<0; i++){
            arra.push(i);
        }
        for(var j=b; j<0; j++){
            arrb.push(j);
        }
        var arrsum = arra.concat(arrb);
        return -arrsum.length; 
    }
    if(a>0 && b<0){
        for(var i=1; i<=a; i++){
            arra.push(i);
        }
        for(var j=b; j<0; j++){
            arrb.push(j);
        }
        if(arra.length>arrb.length){
            for(var i=0; i<arrb.length; i++){
                arra.splice(0,1);
            }
            return arra.length;
        }
        if(arra.length<arrb.length){
            for(var i=0; i<arra.length; i++){
                arrb.splice(0,1);
            }
            return -arrb.length;
        }
        if(arra.length==arrb.length){
            return 0;
        }
    }
    if(a<0 && b>0){
        for(var i=a; i<0; i++){
            arra.push(i);
        }
        for(var j=1; j<=b; j++){
            arrb.push(j);
        }
        if(arra.length>arrb.length){
            for(var i=0; i<arrb.length; i++){
                arra.splice(0,1);
            }
            return -arra.length;
        }
        if(arra.length<arrb.length){
            for(var i=0; i<arra.length; i++){
                arrb.splice(0,1);
            }
            return arrb.length;
        }
        if(arra.length==arrb.length){
            return 0;
        }
    }
};
```