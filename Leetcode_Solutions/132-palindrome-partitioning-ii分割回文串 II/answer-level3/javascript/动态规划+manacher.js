代码还没有优化过，只是给大家提供一个思路而已。
**首先**想到的是动态规划，dp[i]的可能性有m+1种，1就是它的前一个字符后切割，而m就是以他为尾缀的所有的回文字符串的数量，我们选其中最小的就好。
**然后**就是想到改怎么去判断回文字符串的数量了。刚好我想练手一下manacher的方法（大家可以自己去网上找哈，大概意思就是在字符串的每个字符间插入一个特殊符号，如‘aab’变型为‘#a#a#b#’，然后我们可以得到的是以某一个字符为回文中心，能得到的最长回文串的半径，对于例子而言就是[1,2,3,2,1,2,1]），他是一个时间复杂度为O(n)的,而且因为我们能知道以每个字符为中心或者相邻两个字符中间为中心的回文字符串的半径了，就没必要每个都来回判断了。简单来说，我觉得能省很多时间。PS：我知道这里我讲的很笼统，所以对于没有学过的manacher，建议还是先去学一下。
**接着**就是整体的思路了：简单的来说我们遍历到了第i位，就要去考虑以它或（i,i+1）中间为中心的所有可能的回文串最后一位字符的最小切割数了（代码上有注释，我觉得思路不麻烦就不具体讲了）。重要的是想解释一下为什么是所有可能的回文串。比如对于‘aa*a*aaa’而言，i=2,那么以他为中心的回文串就有‘a*a*a’,'aa*a*aa'('*a*a'是以他们两个字符的中间为中心)，对于他们各自的尾缀字符都有影响，所以都要记录一下。

```
/**
 * @param {string} s
 * @return {number}
 */
var minCut = function(s) {
    if(s.length<=1) return 0;
    var lstRadios=manacher(s);
    var dp=[];
    for(var i=0; i<s.length; i++){
        if(dp[i] == undefined) dp[i]=i;
        if(i!=0)dp[i]=Math.min(dp[i-1]+1,dp[i]);
        //先以i为中点
        var d=lstRadios[2*i+1]/2 - 1;
        for(var j=1; j<=d; j++){
            if(dp[i+j] == undefined) dp[i+j]=i+j;
            dp[i+j]=Math.min(((i-j-1)>=0?(dp[i-j-1]+1):0),dp[i+j]);
        }
        //以i和i+1的中间为中心
        d=lstRadios[2*i+2]/2;
        if(d<=0)continue;
        for(var j=1; j<=d; j++){
            if(dp[i+j] == undefined) dp[i+j]=i+j;
            dp[i+j]=Math.min(((i-j)>=0?(dp[i-j]+1):0),dp[i+j]);
        }
    }
    return dp[s.length-1];
};

var manacher = function(s){
    if(!s) return [];
    var lstRadios=[];
    //拼装manacher字符串
    s=s.replace(/\w/g,(a)=>{return '#'+a;})+'#';
    //三个指针，现在先定义中心指针c和最右指针r,剩下一个就是运动指针了
    var r=-1, c=-1;
    for(var i=0; i<s.length;i++){
        //判断i在不在r右侧
        //在，当前指针对应的半径无从判断，先赋值1
        //不在，就判断当前i以c为中心的对应指针i'的半径，
        //如果i'的半径超过了c半径的范围，就说明i的半径就为r-i+1；
        //如果i'的半径刚好在c半径的的范围内，且不在边界上，那么i的半径就为i'的半径
        //如果i'的半径刚好在c半径的指针上，那么i的半径是有可能再扩大的，需要再验证
        lstRadios[i]=r>i?Math.min(lstRadios[2*c-i],r-i+1):1;

        while(i+lstRadios[i]<s.length && i-lstRadios[i]>-1){
            if(s.charAt(i-lstRadios[i]) == s.charAt(i+lstRadios[i]))lstRadios[i]++;
            else break;
        }

        if(i+lstRadios[i]-1 > r){
            r=1+lstRadios[i]-1;
            c=i;
        }
    }
    return lstRadios;
}
```
