var isPalindrome = function(x) {
   if(x<0){
       return false;
   } 
    var x=x.toString();
    var x1=[];
    var x2=[];
    for(var i=0;i<x.length;i++){
        x1.push(x[i]);
        x2.push(x[x.length-1-i]);
    }
    var x1=x1.join("");
    var x2=x2.join("");
    if(x1==x2){
        return true;
    }else{
        return false;
    }
};