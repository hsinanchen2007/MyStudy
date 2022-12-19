### 解题思路
看到通过测试有点开心，结果...
![微信图片_20200123231356.png](https://pic.leetcode-cn.com/f8b477d88775d641aeaa0715598b158083d70f8503e0034077e144c4eaaeb2ba-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200123231356.png)

我这些的都是什么呀！

我的思路比较直接，使用数组indexof的方法可以找出是否有同样的字符，-1：无，若无则将字符存进去，
如有：数组从index索引开始切
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var difStr=[];
    var maxDifStr=[];
    var len=0;
    var maxLen=0;
    for(var i=0;i<s.length;i++){
    	var str=s[i];
    	var searchIndex=difStr.indexOf(s[i]);
    	if(searchIndex==-1){
    		difStr.push(s[i]);
    		len++;
    		// maxLen=maxLen<len?len:maxLen;
    		if(maxLen<len){
    			maxLen=len;
    			maxDifStr=difStr;
    		}
    	}else{
    		// maxLen=maxLen<len?len:maxLen;
    		if(maxLen<len){
    			maxLen=len;
    			maxDifStr=difStr;
    		}
    	difStr=difStr.splice(searchIndex+1,difStr.length);
    		difStr.push(str);
    		len=difStr.length;
    	}
    }
    return maxLen;
};
```