### 解题思路
方法一：字符串转数组，通过计数器统计形成单词的长度
方法二：通过 Map 对字母表出现的字母计数

### 代码

```javascript
/**
 * @param {string[]} words
 * @param {string} chars
 * @return {number}
 */
// 方法一：字符串转数组，通过计数器统计形成单词的长度
var countCharacters = function(words, chars) {
    // 记录总数
    let countSum = 0;
    for(let i = 0; i < words.length; i++){
        // 将字符串转化成数组
        let charsCopy = chars.split("");
        // 每个词汇、每个词汇的长度、当前词汇每个字母在字母表中存在的数量
        let word = words[i],wordLength = word.length,count=0;
        // 优化点1：单词的长度一定不能大于字母表的长度
        if(wordLength > charsCopy.length){
            continue;
        }
        // 遍历每个单词中的字母进行比较
        while(wordLength>0){
            // 获取当前字母所在字母表中的下标
            let index = charsCopy.indexOf(word[wordLength-1]);
            if(index > -1){
                // 如果存在计数加一并将字母表中对应位置置空
                charsCopy[index] = null;
                count++;
                wordLength--;
            }else{
                // 优化点2：单词中只要出现不在字母表中的字母时结束当前单词的遍历
                break;
            }
        }
        // 当计数大小等于当前单词长度时 将当前单词长度累加到总数上
        if(count === word.length){
            countSum += count
        }
    }
    return countSum;
};
// 方法二：通过 Map 对字母表出现的字母计数
var countCharacters = function(words, chars) {
    // 创建一个计数器
    let countSum = 0,charsMap = stringToMap(chars);
    // 遍历词汇表
    for(let j = 0; j < words.length; j++){
        // 复制一份字母 Map 表、当前单词项、当前单词长度、是否满足条件的单词
        let word = words[j], flag = true;
        // 优化1：当前单词长度大于字母表长度时 直接跳过此单词的
        if(word.length > chars.length){
            continue;
        }
        // 
        let wordMap = stringToMap(word);
        for(let charItem in wordMap){
            // 单词中字母出现的次数比字母表出现的次数多时即为不满足条件的单词
            if(wordMap[charItem] > charsMap[charItem] || !charsMap[charItem]){
                flag = false;
                break;
            }
        }
        // 当计数大小等于当前单词长度时 将当前单词长度累加到总数上
        if(flag){
             countSum += word.length;
        }
    }
    return countSum;
};
// 将字符串转为map结构
function stringToMap(chars){
    let charsMap = new Map();
    // 将字母表进行进行 Map 存储，key 是字母项，value 是出现的次数
    for(let i = 0; i < chars.length; i++){
        charsMap[chars[i]] = charsMap[chars[i]] ? charsMap[chars[i]] + 1 : 1;
    }
    return charsMap;
}
```