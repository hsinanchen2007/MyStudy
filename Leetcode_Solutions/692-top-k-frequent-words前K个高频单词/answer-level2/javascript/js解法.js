![image.png](https://pic.leetcode-cn.com/e42ec4c5f576f28a19616519f42085735d92f68369592e8643ca81ec403707d7-image.png)

思路：
1. 建立一个哈希表，存储每个单词出现的次数
2. 把map转为数组，按照单词出现次数从大到小排列
3. 再次遍历一遍数组，把出现次数相同的单词按照字符串排序，小的在前（ 比如：'bbc', 'abc' 都出现5次，但是根据题目要求需要把'abc'放在前面 ）
4. 此时因为已经按照题目要求排好序了，那就从数组中拿出k个单词放到结果中，返回就可以了

```javascript
var topKFrequent = function(words, k) {
  let map = new Map(),
        result = [];

  words.forEach((item) => {
    let num = map.get( item );
    if (num === undefined) {
      map.set( item, 1 );
    }
    else {
      map.set( item, num + 1 )
    }
  })

  map = Array.from( map );

  map.sort((a, b) => {
    return b[1] - a[1];
  });

  let start = 0, val = null;
  for (let i = 0; i < map.length; i++) {
    if (val === null) {
      val = map[i][1];
    }
    else {
      if (map[i][1] !== val) {
        // 拿出去排序，拿回来拼接
        let section = map.slice(start, i);
        section.sort( (a, b) => {
          return a[0] > b[0] ? 1 : -1;
        });
        map.splice(start, i - start, ...section);
        // 初始化 start end val
        start = i;
        val = map[i][1];
      }
    }
  }

  if (start !== null) {
    let section = map.slice(start, map.length);
    section.sort( (a, b) => {
      return a[0] > b[0] ? 1 : -1;
    });
    map.splice(start, map.length - start, ...section);
  }

  for (let i = 0; i < k; i++) {
    if (map[i]) {
      result.push( map[i][0] );
    }
  }

  return result;
};
```