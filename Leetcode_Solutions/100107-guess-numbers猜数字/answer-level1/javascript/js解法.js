```
var game = function(guess, answer) {
    var times = 0;
    for(let i in guess){
        if(answer[i] == guess[i]){
            times += 1;
        }
    }
    return times;
};
```