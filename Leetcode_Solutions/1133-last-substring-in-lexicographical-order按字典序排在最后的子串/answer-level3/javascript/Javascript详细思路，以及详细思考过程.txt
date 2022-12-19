首先想到：找出**字符串中字典序最大的字母**，然后再求以该字母为首的子串的最大值。  
然后再归纳总结的过程中会发现：

**前面一截相同，那么肯定是越长的子串字典序越大**  

因此`abcd`一定比`abcdX`要小，同样道理`abcdX`一定比`abcdXY`要小
因此以某个字符`x`开头的子串最大的一定是以`x`所在位置为起点、`s`最后一个字符为终点的子串，即：

```
x开头的最大子串 = s.substr(x所在索引)
```

弄清楚了这点之后题目就简单了，可以分为以下几个步骤

1. 找出字典序最大的字符`x`
2. 由前往后、或者由后往前依次找到每一个以“`x`开头的最大子串”
3. 依次对比每一个“`x`开头的最大子串的大小”、取其最大的那个即为所求  

```js
var lastSubstring = function(s) {
	// 找出字典序最大的字母:char
	let arr=new Array(26).fill(0);
    for(let c of s){
        arr[c.charCodeAt()-97]=1;
    }
    let char;
    for(let i=arr.length-1;i>=0;i--){
        if(arr[i]>0){
            char=String.fromCharCode(i+97);
            break;
        }
    }
    
    //由前至后依次找出所有以char开头的最大子串，并取其中字典序最大的子串
    let index=-1;
    let ans = ""
    while((index=s.indexOf(char,index+1))>=0){
        if(s.substr(index)>ans){
            ans = s.substr(index);
        }
    }
    return ans;
}
```
但是到此为止还不是最简单的方案，因为我们还需要先求出最大的字符`x`,其实这个最大的字符`x`也不用求，因为上面有说过以`x`开头的最大子串一定为`s.substr(x所在索引)`,因此可以直接依次遍历每个索引对应的最大子串，找出其中最大的即为所求!  

最终代码为：  

```javascript
var lastSubstring = function(s) {
    let ans = ""
    for(let i=0;i<s.length;i++){
        if(s.substr(i)>ans){
            ans = s.substr(i);
        }
    }
    return ans;
};
```
