小白解法  因为是两个数组  不用循环直接比较即可
var game = function(guess, answer) {
    let n = 0
    if(guess[0]==answer[0]){
        n++;
    };
    if(guess[1]==answer[1]){
        n++;
    };
    if(guess[2]==answer[2]){
        n++;
    };
    return n;

};