### 思路
思路很直接，用哈希表的方法来做，用 `map`来存储字母相同的单词，将每一个单词的字母排序后用作`key`, 保证相同字母的单词的`key`相同，遍历一次数组即可将所有字母相同的单词放在同一`key`中。
### 题解
```JavaScript []
var groupAnagrams = function (strs) {
    const map = new Map();

    const getKey = (a) => {
        // 将字母排序后用作 map key，如 'eve' => 'eev'， 'vee' => 'eev'
        return a.split('').sort().join('')
    }

    for (let item of strs) {
        // 获取 item 的 key，保证相同字母组合的 key 相同。
        const key = getKey(item);
        if (map.get(key)) {
            map.get(key).push(item);
        } else {
            map.set(key, [item]);
        }
    }
    return [...map.values()];
};
```