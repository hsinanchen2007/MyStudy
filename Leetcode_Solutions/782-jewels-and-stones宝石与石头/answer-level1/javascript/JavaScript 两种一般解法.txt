```
var numJewelsInStones = function(J, S) {
    let c=0;
    for( let i in S ){
        if( J.includes(S[i]) )c++;
    }
    return c;

    //let a = S.match( new RegExp( '[' +J +']'  ,'g') )
    //return a == null ? 0 : a.length;
};
```
