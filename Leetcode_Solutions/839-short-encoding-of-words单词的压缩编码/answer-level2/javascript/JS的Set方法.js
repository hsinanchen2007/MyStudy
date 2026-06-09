### 解题思路
用set不断剔除重复值
不要被题意搞蒙了 我们需要返回的是长度
不需要去拼接返回数组 所以只需要找到重复的剔除
就可以

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function (words) {
    let wordsSet = new Set(words);//根据set中无重复值
    wordsSet.forEach((item) => {
        for (let i = 1; i < item.length; i++) {//从1开始向后切
            let target = item.slice(i);//切片不断变化
            console.log(target)
            wordsSet.has(target) && wordsSet.delete(target);//判断 如果有重复就删除
            // 不用管拼接  我们计算的是最后的长度
        }
    })

    let result = 0;
    // 每一个元素都要加上一个#的长度 返回总长度
    wordsSet.forEach(item => result += item.length + 1)
    return result
};
```