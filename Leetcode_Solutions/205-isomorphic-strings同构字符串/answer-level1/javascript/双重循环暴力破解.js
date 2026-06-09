```
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    let one = s.split('');
    let two = t.split('');

    let only = (arrone,arrtwo) => {
        for(let i=0;i<arrone.length-1;i++){
            for(let j=i+1;j<arrone.length;j++){
                if((arrone[i] == arrone[j] && arrtwo[i] != arrtwo[j]) ||
                    (arrone[i] != arrone[j] && arrtwo[i] == arrtwo[j])
                ){
                    return 1;
                }
            }
        }
    }

    let zero = only(one,two);
    if(zero == 1){
        return false;
    }
    return true;
};
```
