+ 把字符串转为数组 通过do while循环删除重复项，每次删除完成重复项后重置索引和length

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var removeDuplicates = function(S) {
    var strArr = S.split('');
    var len = strArr.length,
        i = 0; 
    do{
        if(strArr[i] === strArr[i+1]){
            strArr.splice(i,2);
            i = i === 0 ? i : --i;
            len = strArr.length;
        }else{
	        i++
	    }
        
    }
    while(i < len)
    return strArr.join('');
};
```
