# 官方提示这是一道贪心算法的题

#### 贪心算法必须具备后无效性，也就是不必考虑前面的影响，只需考虑当前的状态。

```
示例 1:
s = "abc", t = "ahbgdc"

返回 true.
```
如上例子
要使字符串s的排序要和字符串t的排序一致，我们只需考虑两个要素
- 当字符'a'出现，判断字符传t中是否存在字符'a'
- t中字符‘a'之后的剩余字符串是否存在’b'


用一句通俗的话就是剩余字符串中是否存在下一个字符；利用贪心算法的概念就是局部是否存在最优解。

**贪心策略：剩余字符串是否存在字符**


```
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    
    let flag=true;
    let str=t;
        
    for(let j=0;j<s.length;j++){
        let i=str.indexOf(s[j]);
        if(i>-1){
            str=str.substr(i+1)
        }else{
            flag=false
            break;
        }
        
    }
        
    return flag
};
```
