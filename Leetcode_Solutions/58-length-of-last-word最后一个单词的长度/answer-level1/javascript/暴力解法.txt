var lengthOfLastWord = function(s) {
    let index
    if(s.length>0){
        index =s.trimEnd().lastIndexOf(' ')
        return s.trimEnd().length-1- index
    }else{
        return 0
    }
};