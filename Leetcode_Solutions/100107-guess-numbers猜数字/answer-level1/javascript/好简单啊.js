js实现
不得不说，这也是我刷leetcoed以来最简单的题目
```
var game = function(guess, answer) {
      let a = 0
    for(let i=0 ;i<3;i++){
        if(guess[i]=== answer[i]){
            a++;
        }
    }
    return a;
};
```