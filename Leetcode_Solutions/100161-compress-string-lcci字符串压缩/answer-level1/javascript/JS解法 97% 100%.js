var compressString = function(S) {
    var arr_cf = [];
    var k = 1;
    for(var i=0;i<S.length;i++){
        if(S[i+1] === S[i]){
            k++;
        }else{
            arr_cf.push(S[i]);
            arr_cf.push(k);
            k=1;
        }
    }
    var last = arr_cf.join('');
    return last.length >= S.length?S:last;
};
