执行用时 : 124 ms, 在Longest Substring Without Repeating Characters的JavaScript提交中击败了99.19% 的用户
内存消耗 : 38 MB, 在Longest Substring Without Repeating Characters的JavaScript提交中击败了82.46% 的用户
```
var lengthOfLongestSubstring = function(s) {
    let num=0,j=0,t=0
    for(let i=0;i<s.length;i++){
        t=s.slice(j,i).indexOf(s[i])
        if(t==-1){
            num=Math.max(num,i-j+1)
        }else{
            j=j+t+1
        }
    }
    return num
    
};
```