用map结果一直不多，后来才发现是用了= 而不是===
```
var game = function(guess, answer) {
    //return Anumber
    let result = 0;
    guess.map(function(item, index){
       
        if(item === answer[index]){
            result++;
        }
    })
    return result
};
```
