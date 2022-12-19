var lengthOfLastWord = function(s) {
    let index
    let arr =[]
    if(s.length>0){
       s =s.trimStart().trimEnd() 
       arr =s.split(' ')
       index = arr[arr.length-1].length
       return index

    }else{
        return 0
    }
};