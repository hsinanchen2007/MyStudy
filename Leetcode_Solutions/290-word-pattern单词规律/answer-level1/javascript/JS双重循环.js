```
/**
 * @param {string} pattern
 * @param {string} str
 * @return {boolean}
 */
var wordPattern = function(pattern, str) {
    let one = pattern.split('');
    let two = str.split(' ');

    console.log(one,two);

    if(one.length !== two.length){
        return false;
    }
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

    let result = only(one,two);

    if(result == 1){
        return false;
    }else{
        return true;
    }
};
```
