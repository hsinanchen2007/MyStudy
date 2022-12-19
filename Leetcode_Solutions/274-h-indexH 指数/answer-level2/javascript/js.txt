
var hIndex = function(citations) {
    
    citations.sort((a,b)=>a-b).reverse();
    for(let i =0;i<citations.length;i++){
        if(i>=citations[i]){
             return i
        }
    }
    return citations.length?citations.length:0
   
};