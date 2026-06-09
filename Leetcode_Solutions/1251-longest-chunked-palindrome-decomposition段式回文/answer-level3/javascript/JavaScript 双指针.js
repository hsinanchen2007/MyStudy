这题实在不该是倒困难题哈！  

左右两边同时遍历，找到相同的`段`时计数+2即可

```javascript
var longestDecomposition = function(text) {
    let i=0,j=text.length-1;
    let word1="",word2="";
    let ans=0;
    while(i<j){
        word1+=text[i++];
        word2=text[j--]+word2;
        if(word1===word2){
            ans+=2;
            word1=word2=""
        }
    }
    //如果i===j表示这段字符串为计数，最中间必定独自为一段
    //如果word1.length>0最后word1+word2必定独自为一段
    return ans+(word1.length>0 || i===j ?1:0);
};
```