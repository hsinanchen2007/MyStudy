var lengthOfLongestSubstring = function(s) {
    var res = 0,
        i = 0, 
        index = 0;
    var temp = [];
    while(i < s.length) {
       index = temp.indexOf(s[i]);
        if(index === -1) {
            temp.push(s[i]);
        } else {
            temp = temp.slice(index+1);
            continue;
        }
        res = Math.max(res, temp.length);
        i++;
    }
    return res;
};