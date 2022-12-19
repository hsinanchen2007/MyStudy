# 贪心-字符串转数组
```
var isSubsequence = function(s, t) {
    if(s.length == 0) return true;
    let sStack = s.split('');
    let tStack = t.split('');
    while(tStack.length>0){
            let tItem = tStack.pop();
            if(tItem == sStack[sStack.length-1]){
                sStack.pop();
                if(sStack.length == 0) return true;
            }
    }
    return false;
};
```
# 贪心-字符串指针
```
var isSubsequence = function(s, t) {
    if(s.length == 0) return true;
    let sPos = 0;
    let tPos = 0;
    let tLen = t.length;
    let sLen = s.length;
    while(tPos < tLen){
        if(t[tPos] == s[sPos]) sPos++;
        if(sPos == sLen) return true;
        tPos++;    
    }
    return false;
};
```
# DP
理论上没啥问题，但架不住字符串t长度大~
双层循环在t字符串长度较大时会超时，所以仅仅是这个方案可行~

```
var isSubsequence = function(s, t) {
    let sLen = s.length, tLen = t.length;
        if (sLen > tLen) return false;
        if (sLen == 0) return true;
        let dp = Array.from({length:sLen + 1});
        dp[0] = Array.from({length:tLen + 1},x=>true);
        for (let i = 1; i <= sLen; i++) {
            dp[i] = Array.from({length:tLen + 1},x=>false);
            for (let j = 1; j <= tLen; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[sLen][tLen];
}
```
# 字典二分查找
题解中有一题是C++写的，参考解法得到~
这种解法的关键就是字符串的字典话，通过map，以及map内value中的二分查找提高查询效率；
而生成字典可存储用于大量输入下的复用，在大量输入的场景下，字典的生成这一个时间可以忽略。
```
//大量字符串重复，将字典缓存会提速，leetcode提交时要把这句放到函数体内
let dp = null;
var isSubsequence = function(s, t) {
    let getDp = function(t){
        let dp = new Map();
        for(let i = 0;i<26;i++) dp.set(String.fromCharCode((97+i)),[]);
        for(let i=0;i<t.length;i++){
            dp.get(t[i]).push(i);
        }
        return dp;
    }
    if(dp == null) dp = getDp(t);
    let tag=-1;
    for(let i=0,len = s.length;i<len;i++){
        let now=s[i];
        let left=0,right=dp.get(now).length-1;
        while(left<right){
            let mid=parseInt((left+right)/2);
            if(dp.get(now)[mid]>tag)
                right=mid;
            else
                left=mid+1;
        }
        if(right<left || dp.get(now)[left]<tag)return false;
        tag=dp.get(now)[left];
    }
    return true;
}
```

