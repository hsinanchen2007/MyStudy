#### 解法一：暴力排序 sort
+ [242题的变种-戳看解法一](https://leetcode-cn.com/problems/valid-anagram/solution/242-you-xiao-de-zi-mu-yi-wei-ci-by-alexer-660/)
```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var tmpCode = '';
    var hashMap = {};
    var result = [];
    for(var i = 0;i<strs.length;i++){
        tmpCode = strs[i].split('').sort().join('');
        if(hashMap[tmpCode]==undefined){
            hashMap[tmpCode] = [];
        }
        hashMap[tmpCode].push(strs[i]);
    }
    for(var key in hashMap){
        result.push(hashMap[key]);
    }
    return result;
};
```
#### 解法二：哈希表
+ [242题的变种-戳看解法二](https://leetcode-cn.com/problems/valid-anagram/solution/242-you-xiao-de-zi-mu-yi-wei-ci-by-alexer-660/)
+ 给每个字符做哈希映射
+ 遍历时，将每个字符hash值相同的归到同一组里去
```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var tmpHash = new Array(26);
    var resultHash = {};
    var out = [];
    for(var i = 0;i<strs.length;i++){
        for(var k = 0;k<26;k++){
            tmpHash[k] = '0';
        }
        var aCode = 'a'.charCodeAt();
        var tmpI = strs[i];
        var len = tmpI.length;
        var resultHashKey = '';
        for(var r = 0;r<len;r++){
            tmpHash[tmpI[r].charCodeAt() - aCode]++;
        }
        var tmpHashKey = tmpHash.join('');
        if(resultHash[tmpHashKey]==undefined){
            resultHash[tmpHashKey] = [];
        }
        resultHash[tmpHashKey].push(tmpI)
    }
    
    for(var key in resultHash){
        out.push(resultHash[key])
    }
    return out;
};
```