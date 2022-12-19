var shortestPalindrome = function(s) {
    if(s.length<=1) return s
    let res = 0,l=s.length
    for(let i=l-1;i>0;i--){
        let h=0,f=i
        while(s[h]==s[f]&&f>=h){
            h++;
            f--
        }
        if(f+1-h+1<=1){
           res=i
           break;
        }
    }
    return s.substring(res+1).split("").reverse().join("").concat(s)
};