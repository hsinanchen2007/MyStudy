方法一：直接暴力法，三重循环，做了剪枝操作468 ms，34.7 MB
```
   var longestPalindrome = function(s) {
         let subStrMax="";
         let subLenMax=0;
         for (let i = 0; i < s.length; i++) {
             let subLen=0;
             for (let j = s.length-1; j >=i ; j--) {
                 let flag=true;//i~j是回文数
                 let k = i,m=j;
                 for (; k <=m; k++,m--) {
                     if(s[k]!==s[m]){
                         flag=false;
                         break;
                     }
                 }
                 if(flag) {
                     subLen=j-i+1;
                     subLenMax=subLenMax>subLen?subLenMax:subLen;
                     subStrMax=subLenMax>subLen?subStrMax:s.substring(i,j+1);
                     break;
                 }
             }

         }
         return subStrMax;
     };
```
方法二，根据官方讲解使用动态规划用时1060 ms	，128.8 MB
```
var longestPalindrome = function(s) {
        let p=[];
        for (let i = 0; i < s.length; i++) {//初始化一回文
            p[i]=[];
            p[i][i]=true;
        }
        for (let i = 0; i <s.length-1; i++) {//初始化二回文
            p[i][i+1]=(s[i]===s[i+1]);
        }
        //从三回文直到最长的回文子串
        for (let h = 2; h < s.length; h++) {//h+1表示回文长度

            for (let i = 0; i <= s.length-h; i++) {
                p[i][i+h]=(p[i+1][i+h-1] && s[i]===s[i+h]);
            }
        }
        let maxSubStr="";
        let maxSubLen=0;
        for (let i = 0; i < s.length; i++) {
            let len=0;
          for(let j = s.length -1; j >= i; j--) {
            if(p[i][j]){len=j-i+1;break;}
          }
          maxSubLen=maxSubLen>len?maxSubLen:len;
          maxSubStr=maxSubLen>len?maxSubStr:s.substring(i,i+len);
        }
        return maxSubStr;
    };
```

动态规划居然还没有直接来的效果好。。。应该还有很大的优化空间
