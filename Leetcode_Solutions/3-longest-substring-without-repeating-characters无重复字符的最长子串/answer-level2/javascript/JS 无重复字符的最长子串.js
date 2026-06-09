## JS 无重复字符的最长子串
![{75FAE3BA-8F3B-4FD4-B7A0-5CE2C420DBA0}_20191017113409.jpg](https://pic.leetcode-cn.com/dddc1cfe4057cf84994379f48cf53015dad343239fa04beb75ec574a63de26f4-%7B75FAE3BA-8F3B-4FD4-B7A0-5CE2C420DBA0%7D_20191017113409.jpg)

---

```
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    var arr = [],idx = 0;
    var result = 0
    arr.forEach.call(s,(val,index)=>{
        let hasIndex = arr.indexOf(val)
        if(hasIndex!==-1){
            arr.length>result&&(result = arr.length)
            arr.splice(0,hasIndex+1)
        }
        arr.push(val)
    })
    return Math.max(result,arr.length)
};
```