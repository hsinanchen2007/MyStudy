### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
//一、hash-set
var minimumLengthEncoding = function (words) {
    // 此题有两个要点,对word数组去重，（去重可以用set） 在循环遍历去重后的words，并循环每个单词的slice，判断是否在words中哟该单词 有的话将该单词去掉！！！ 最后在计算总的字典长度
    let set = new Set(words);
    for (let word of set) {
        for (let i = 1; i < word.length; i++) {
            let temp = word.slice(i);
            set.has(temp) && set.delete(temp);
        }
    }
    let res = [...set].reduce((acc,cur)=>{
        return acc+cur.length+1;
    },0)
    return res;
};
```