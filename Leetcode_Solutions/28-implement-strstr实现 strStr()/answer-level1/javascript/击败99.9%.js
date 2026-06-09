![28.png](https://pic.leetcode-cn.com/7b58ca0fa15339478466be2789bc8988215693ba8cde0f304b56909cf85c4312-28.png)  

```
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    if(needle == ""){
      return 0;
    }
    let temp = haystack.split(needle);
    if(temp.length > 0 && temp[0].length != haystack.length){
      return temp[0].length;
    }else{
      return -1;
    }
};
```

