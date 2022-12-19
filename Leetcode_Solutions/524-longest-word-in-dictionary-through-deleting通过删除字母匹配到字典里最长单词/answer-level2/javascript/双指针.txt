### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string[]} d
 * @return {string}
 */
var findLongestWord = function(s, d) {
    // 先将数组按字典序排
    d = d.sort();
    let index=0,maxWord = '';
    // 遍历数组
    while(index<d.length){
        nowComparing = d[index];
        if(nowComparing.length>maxWord.length){
            // 如果正在对比的word 要比之前的长
            if(isSub(s,nowComparing)){
                maxWord = nowComparing;
            }
        }
        ++index;

    }
    return maxWord;
};
const isSub = function(s,key){
    let k=0,i_s=0;
    while(k<key.length){
        // 短字符的每一位都要在长的里
        if(i_s>s.length){
            return false;
        }
        if(s[i_s]==key[k]){
            ++k;
        }
        ++i_s;
    }
    return true
}
```