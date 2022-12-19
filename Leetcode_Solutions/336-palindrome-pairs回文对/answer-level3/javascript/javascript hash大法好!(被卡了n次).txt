```
/**
 * @param {string[]} words
 * @return {number[][]}
 */
var hash = [];
var mod = 1000000007;
function Pow(n) {
    var base = 26;
    var ret = 1;
    while (n != 0) {
        if ((n & 1) == 1) ret = ret * base % mod;
        base = base * base % mod;
        n >>= 1; 
    }
    return ret;
}
function gethash(s) {
    var ret = [[],[]];
    if (s.length == 0) {
        ret[0].push(0);
        ret[1].push(0);
        return ret;
    }
    var len = s.length;
    var last = 0;
    for (var i = 0; i < len; ++i) {
        last = (last * 26 % mod + s.charCodeAt(i)) % mod;
        ret[0].push(last);
    }
    last = 0;
    for (var i = len - 1; i >= 0; --i) {
        last = (last * 26 % mod + s.charCodeAt(i)) % mod;
        ret[1].push(last);
    }
    ret[1].reverse();
    return ret;
}
function judge(i, j, words) {
    var lena = words[i].length, lenb = words[j].length;
    if (lena + lenb == 1) return true;
    var mid = lena + lenb >> 1;
    var left, right, delta = ((lena + lenb) % 2 == 0 ? 1 : 2);
    if (mid <= lena) {
        left = hash[i][0][mid - 1];
        if (mid + delta > lena) {
            right = hash[j][1][mid + delta - lena - 1];
        }
        else {
            right = (hash[j][1][0] * Pow(lena - mid - delta + 1, mod) % mod + hash[i][1][mid + delta - 1]) % mod;
        }
    }
    else {
        left = (hash[i][0][Math.max(lena - 1, 0)] * Pow(mid - lena, mod) % mod + hash[j][0][mid - lena - 1]) % mod;
        right = hash[j][1][mid - lena - 1 + delta];
    }
    return left == right;
}
var palindromePairs = function(words) {
    console.log(words.length);
    var ret = [];
    hash = [];
    var len = words.length;
    for (var i = 0; i < len; ++i) {
        hash.push(gethash(words[i]));
    }
    for (var i = 0; i < len; ++i) {
        for (var j = 0; j < len; ++j) {
            if (i == j) continue;
            if (judge(i, j, words)) ret.push([i, j]);
        }
    }
    return ret;
};
```
