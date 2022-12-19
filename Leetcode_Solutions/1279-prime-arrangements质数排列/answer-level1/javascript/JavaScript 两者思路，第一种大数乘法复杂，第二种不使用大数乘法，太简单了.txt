问题很简单，就是质数的数的全排列乘上剩下的数的全排列就好了。计算这个答案有两个思路，第一种，前者前排列算好乘上后者全排列，得到的两个全排列就会非常大，javascript没办法直接进行这种超大位数的运算，会出现舍掉的情况，所以就需要大数计算，但是大数计算还是比较复杂的，特别是它最后要求的求余，我做不到，所以就换了个思路，它不是1e+9+7么，那么就说么7对于1e+9的影响的相当有限的，那么其实就是去整1e+9，然后考虑一下7的影响，就可以求出答案了。代码如下
```
/**
 * @param {number} n
 * @return {number}
 */
var numPrimeArrangements = function(n) {
    var table = [2];
    var primecount = 1;
    var primeproduct = 1;
    var n_primecount = 1;
    var n_primeproduct = 1;
    for(var i=3; i<=n; i++){
        var length = table.length;
        for(var j=0; j<length; j++){
            if(i%table[j]==0) break;
        }
        if(j==length){
            table.push(i);
            primecount++;
            primeproduct=(primeproduct*primecount)%(1e+9+7);
        }else{
            n_primecount++;
            n_primeproduct=(n_primeproduct*n_primecount)%(1e+9+7);
        }
    }

    num = Math.floor((n_primeproduct*primeproduct)/(1e+9));
    num -= Math.ceil((num*7-(n_primeproduct*primeproduct)%(1e+9))/(1e+9));
    if(n>=44) return parseInt(bigminus(bigmult(primeproduct,n_primeproduct),bigmult(num,1e+9+7)))
    else return (n_primeproduct*primeproduct)%(1e+9+7);
    
};

var bigmult = function(a,b){
    var aArray = a.toString().split("");
    var bArray = b.toString().split("");
    var length = aArray.length+bArray.length;
    var product = new Array(length);
    for(var i=0; i<length; i++) product[i]=0;
    for(var i=aArray.length-1; i>=0; i--){
        for(var j=bArray.length-1; j>=0; j--){
            product[i+j+1] += parseInt(aArray[i])*parseInt(bArray[j]);
        }
    }
    for(var i=length-1; i>=0; i--){
        if(product[i]>=10){
            var num = product[i];
            product[i]=0;
            var inc = 0;
            while(num!=0){
                product[i-inc]+=num%10;
                num=Math.floor(num/10);
                inc++;
            }
        }
    }
    while(product[0]==0) product.shift();
    return product.join("");
}

var bigminus = function(a,b){ //a>b>0
    var Alength = a.length;
    var Blength = b.length;
    if(a==b) return -1;
    if(Alength<Blength) return -1;
    if(Alength==Blength){
        index=0;
        while(a[index]==b[index]) index++;
        if(a[index]<b[index]) return -1;
    }
    var minus = new Array(Alength);
    for(var i=0; i<Alength; i++){
        minus[i]=parseInt(a[i]);
    }
    for(var i=1; i<=Blength; i++){
        minus[Alength-i] -= parseInt(b[Blength-i]);
        if(minus[Alength-i]<0){
            minus[Alength-i-1]--;
            minus[Alength-i]+=10;
        }
    }
    while(minus[0]==0) minus.shift();
    return minus.join("");
}
```
这样写，确实有点取巧。

还有一种思路，简单多了，其实，**为什么要去先求两者的全排列呢？？为什么不把两者的全排列一起算然后步步取余呢？？**
我写的时候一直被这个蒙蔽了，到上面的代码写完才反应过来。原理如下：
(25!*75!)%(1e+9)=(...(((...*a)%(1e+9))*(a+1)%(1e+9))...)
实现代码如下，太简单了：
```
var numPrimeArrangements = function(n) {
    var table = [2];
    var primecount = 1;
    var n_primecount = 1;
    var product = 1;
    for(var i=3; i<=n; i++){
        var length = table.length;
        for(var j=0; j<length; j++){
            if(i%table[j]==0) break;
        }
        if(j==length){
            table.push(i);
            primecount++;
            product=(product*primecount)%(1e+9+7);
        }else{
            n_primecount++;
            product=(product*n_primecount)%(1e+9+7);
        }
    }
    return product%(1e+9+7);
};
```



