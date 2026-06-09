`var lengthOfLongestSubstring = function(s) {
    let r = ''
    let len = 0
    for (let i in s ) {
        let p = r.indexOf(s[i])
        if (p < 0) {
            r = r + s[i] 
        } else  {
            len = Math.max(r.length, len)
            r = r.substr(p+1) + s[i]
        }
    }
    return Math.max(r.length, len)
};`