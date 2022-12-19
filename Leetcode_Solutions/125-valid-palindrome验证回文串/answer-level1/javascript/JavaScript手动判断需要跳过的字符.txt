```
var isPalindrome = function(s) {
    if(!s) return true
    // 无视大小写的话就全部转化成大写或者小写
    s = s.toLowerCase()
    // 从右向左的指针
    let j = s.length - 1
    // 由于是往中间逼近，那么循环到一半就可以了
    for(let i = 0; i < Math.floor(s.length/2); i++){
        // 将正则改为了手动判断
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
            if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')){
                if(s[i] == s[j])
                    j--
                else{
                    return false
                }
            }else{
                j--
                i--
            }
        }
    }
    return true
};
```
