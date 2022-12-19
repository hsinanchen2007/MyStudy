我们先预设一个字符就是要得到的前缀，这个预设的字符取数组中第一个字符，认为它是我们的前缀，用前缀和第二个字符比较，不满足就减一，获取到满足条件的前缀，然后和第三个字符比较，因为这个前缀是肯定满足第二个的，即使这个前缀减去一些字符还是肯定会满足前面的字符，最终获取到我们需要的字符

```
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let  re=strs[0]||"";
    if(strs.length==1){
       return strs[0]
    }
    for(let i=0; i<strs.length;i++){
       
        while(strs[i].slice(0,re.length)!==re){
              re=re.slice(0,re.length-1)
          }
    }
    
    return re
    
};
```

