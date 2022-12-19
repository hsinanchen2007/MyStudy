[https://leetcode-cn.com/problems/longest-common-prefix)
##总结
很多js的写法还是不熟悉，只能说写的大部分是但是的if else， for loop之类的
现在熟悉了一些新的方法 比如indexOf, charAt, slice, substr, 
还有很多es6的写法 let in, j简化if else
解一：
双重for循环，strs[i][j]!=strs[0][j]
逐位比较，比较全部通过时re增加当前字符，不通过时直接返回re。
```
var longestCommonPrefix = function(strs) {
    var re = '';
    if (!strs.length) return re;
    for (var j=0;j<strs[0].length;j++){//第j位 第一个字符串
        for (var i=1;i<strs.length;i++){//第i个 所有字符串 里面与外面比较
            if (strs[i][j]!=strs[0][j]) return re  //只要不碰到结束条件 全部加入到re
        }
        re += strs[0][j];
    }
    return re;
};
```
substr
```
var longestCommonPrefix = function(strs) {
    if(!strs.length) 
        return "";
    let ans = strs[0];
    for(let i =1;i<strs.length;i++) {
        
        for(let j in ans.length) { //看他们能到第几个j，到了结束判断 返回结果
            if(ans[j] != strs[i][j])
                break;
        }
        ans = ans.substr(0, j);
        if(ans === "")
            return ans;
    }
    return ans;
    
        
};

```
charAt
```
//用charAt取元素，再用substring取子字符串
// "static void main" must be defined in a public class.
public class Main {
    public static longestCommonPrefix(String[] strs) {
        if(!strs.length) return "";
        for(let i = 0; i<strs[0].length; i++) {
            //没一次i的变换截取该i所在的值 与 后面元素进行对比， 取子字符串
            char c = strs[0].charAt(i);
            for(let j = 1; j<strs.length; j++){
                if(c != strs[j].charAt[i]) 
                    retrn strs[0].substring(0, i)
            }
        }
        return strs[0]
            
    }
}
```
```
//code with js
var longestCommonPrefix = function(strs) {
    if(!strs.length) 
        return "";
    for(let i in strs[0].length)
        let c = strs[0].charAt(i)
        for(let j = 1; j<strs.length; j++)
            if(c != strs[j][i]) return strs[0].substring(0, i);
    return strs[0] //没有怎么办？
        
};
```
一个逻辑不清晰的案例， substr
```
(function main() {
var longestCommonPrefix = function(strs) {
    if(strs.length == 0) 
        return "";
    let ans = strs[0]; //flower
    for(let i =1;i<strs.length;i++) {
        let j=0;
        for(;j<ans.length && j < strs[i].length;j++) { 第一个字符串的长度
            if(ans[j] != strs[i][j])//先比较所以再往后移动这样效率很低
                break;
        }
        ans = ans.substr(0, j);
        if(ans === "")
            return ans;
    }
    return ans;
    
        
};
//修改后 i，j调换位置
    var longestCommonPrefix = function(strs) {
    if(strs.length == 0) 
        return "";
    let ans = strs[0]; //flower
    for(let i =0;i<ans.length;i++) {
        let j=1;
        for(;j<strs.length;j++) { 第一个字符串的长度
            if(ans[i] != strs[j][i])//先比较所以再往后移动这样效率很低
                break;
        }
        ans = ans.substr(0, i);
        if(ans === "")
            return ans;
    }
    return ans;
    
        
};
=

}());
```
用indexOf返回首次出现的位置
```
var longestCommonPrefix = function(strs) {
    let t = strs[0] || '';
    let i = 1;
    while(t && i < strs.length) {
        if(strs[i].indexOf(t) != 0) { //indexof返回字符首次出现的位置
            t = t.slice(0, t.length - 1);
        } else {
            i++;
        }
    }
    return t;
    //第二种写法
    let t = strs[0] || '' // t = flower 加入flower 不符合 =》 flow =》 flo 直到 找到前缀
    let i = 1
    while (t && i < strs.length)
        strs[i].indexOf(t) != 0 ? t = t.slice(0, t.length -1) : i++
    return t
};
```
解二：

解一的递归版本，需要增加一些判断语句。
```
var longestCommonPrefix = function (strs,re = '') {
    if (!strs.length) return re;
    if (strs.length == 1) return strs[0];
//将所有字符串的一个与第一个比较，字符串符合要求加入re，并将slice后的放入递归
    for (var i = 1; i < strs.length; i++) {
        if (!strs[i][0]) return re
        if (strs[i][0] != strs[0][0]) return re
        strs[i] = strs[i].slice(1,strs[i].length);
    }
    re += strs[0][0];
//同时放入re后，第一个字符串也应该slice
    strs[0] = strs[0].slice(1,strs[0].length);
//strs 由第一个和i后的字符串组成所以slice他们，相当于slice strs
    return longestCommonPrefix(strs, re);
};
```
解三：

和解一恰好相反，re初始化为数组中第一个元素，逐个比较，当比较通过时返回re，否则削去末位直至比较通过。这里的比较使用了正则表达式。
```
var longestCommonPrefix = function(strs) {
    var re = strs[0] ? strs[0]:'';//f re = flower
    for (var i=1;i<strs.length;i++){
        var regex = new RegExp('^'+re); //^flower
        while (!regex.test(strs[i])&&re.length){
//re等于第一个元素 不完全符合匹配的字符串则slicere，匹配规则修改为新的re，
            re = re.slice(0,re.length-1);
            regex = new RegExp('^'+re);
        }
    }
    return re;
};
```
