方法一：
```
var strStr = function(haystack, needle) {
    return haystack.indexOf(needle);
};
```
方法二：
```
var strStr = function(haystack, needle) {
    if(needle == '') return 0;
    let haystackArr = haystack.split('');
    let needleArr = needle.split('');
    let tempCur = 0;
    let needleCur = 0;
    for(let i = 0,len = haystackArr.length;i<len ;i++){
        tempCur = i;
        while(haystackArr[tempCur] == needleArr[needleCur]){
            if(needleCur == (needleArr.length-1)){
               return i;
            }
            needleCur++;
            tempCur++;
        }
        needleCur = 0;
    }
    return -1;
};
```
方法三
```
var strStr = function(haystack, needle) {
    if(needle == '') return 0;
    let haystackArr = haystack.split('');
    let needleLen = needle.length;
    for(let i = 0,len = haystackArr.length;i<len ;i++){
        if(haystack.substr(i,needleLen) == needle){
           return i;
        }
    }
    return -1;
};
```
