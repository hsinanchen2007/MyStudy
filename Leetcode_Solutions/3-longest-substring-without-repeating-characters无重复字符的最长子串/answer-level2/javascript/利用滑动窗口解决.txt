### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s=="") return 0;
    var max=1;
    var slide=1; //窗口滑动值
    for(var i=1;i<s.length;i=i+slide){
        var flag=true;
        var tmp=s.substr(i-max,max+1);
        for(var j=0;j<=max;j++){
            if(tmp.indexOf(tmp[j])!=tmp.lastIndexOf(tmp[j])){
                slide=tmp.indexOf(tmp[j])+1;
                flag=false;
                break;
            }
        } //检测滑动范围内新加的字符是否有重复
        if(flag){
            max++; //均无重复加1
            slide=1;
        }
    }
    return max;
};
```