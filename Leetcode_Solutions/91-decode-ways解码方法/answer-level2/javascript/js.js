var numDecodings = function(s) {
    if(s[0] == '0'){
        return 0
    }
    var pre = 1
    var curr = 1
    for(var i = 1;i < s.length;i++){
        var temp = curr
        if(s[i] == '0'){
            if(s[i - 1] == '1' || s[i - 1] == '2'){
                curr = pre
            }else{
                return 0
            }
        }else if(s[i - 1] == '1' || s[i - 1] == '2' && s[i] >= 1 && s[i] <= 6 ){
            curr = curr + pre
        }
        pre = temp
    }
    return curr

};

