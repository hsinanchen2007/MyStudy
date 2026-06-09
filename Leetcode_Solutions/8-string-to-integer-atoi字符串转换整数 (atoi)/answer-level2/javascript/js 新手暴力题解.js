var myAtoi = function(x) {
    var p1 = /^[a-z]/gi;
    var p2 = /(\-|\+)?[0-9]{0,}\S/;
    var ans = parseInt(x.match(p2));
   
    if(p1.test(x[0])){
        return 0 ;
    }else if(ans<=-2147483648){
        return -2147483648;
    }else if(ans>=2147483648){
        return 2147483648;
    }else if(isNaN(ans)){
        return 0;
    }else{
        return ans;
    }
};
