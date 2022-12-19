var game = function(guess, answer) {
        var num = 0;
        for(var n= 0;n<3;n++){
            if(guess[n]===answer[n]){
            num++
            }
        }
        
        return num
};