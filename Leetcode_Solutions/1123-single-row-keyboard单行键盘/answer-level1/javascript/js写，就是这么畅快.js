var calculateTime = function(keyboard, word) {
    var result=0;
    var preIndex = 0;
    for(let i=0;i<word.length;i++){
        var letter = word[i];
        var index = keyboard.indexOf(letter);
        result +=Math.abs(index - preIndex);
        preIndex = index;
    }
    return result;
};