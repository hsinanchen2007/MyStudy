![image.png](https://pic.leetcode-cn.com/3c9b6bbb243a0491b314c19e9d787e8d302d99dcc8d93717362e93b2edccd46d-image.png)

看题解中js的很少，所以写一个给大家参考，效率还不错，也是研究了官方的思路两天才写出来，哈哈
这里爆料一下自己：我们在查找过程中肯定是要判断我们当前查找的区间是否是一个有效区间，我开始写的判断条件是：判断两个对象是否相等，最终提交通过之后所需时间是400ms左右，后来参考官方和其他人的思路，使用一个数值来判断是否等于t的长度，只不过累加和累减是有条件的，在下方代码注释中标注了，优化完之后，执行时间变成了100ms左右

思路：这里思路就不解释了（偷个懒），因为和官方的一样，大家还是看看官方的思路，具体每一步的小思路，写在代码注释里面，方便大家理解

```javascript
// 拿这个例子举例：输入: S = "ADOBECODEBANC", T = "ABC"
var minWindow = function(s, t) {
  let left = 0,
      right = 0,
      need = {}, // 使用 object 存储 t 中的每个字符的所需数量
      map = {}, // 当前区间的有效字符以及数量
      count = 0, // 存储有效字符数量， 用来判断找到一个有效区间（ 判断条件：count === t.length ）
                 // !!!考虑到 t 中有重复的字符串，所以count的累加和累减需要注意两点:
                 // 累加的条件：当前区间( map )内的当前字符的数量 小于 ( need )中的当前字符串的数量 => 执行count++
                 // 累减的条件：当前区间( map )内的当前字符的数量 等于 ( need )中的当前字符串的数量 => 执行count--
      r = true, // true: 上一次是 right指针 右移 | false: 上一次是 left指针 右移
      result = ''; // 初始化最终结果字符串
  
  // 初始化need 和 map，map用来记录，need作为符合条件 用作map的对比
  for (let i = 0; i < t.length; i++) {
    need[ t[i] ] = need[ t[i] ] === undefined ? 1 : need[ t[i] ] + 1;
    map[ t[i] ] = 0;
  }
  // 初始化之后 need: { A: 1, B: 1, C: 1 }   map: { A: 0, B: 0, C: 0 }
  
  while (right < s.length) { // 终止条件的意思是：right指针到达最右侧，不会再有新的有效区间了，循环停止，当前的有效区间即为最小区间
    if (r) { // 如果上一次是 right指针 右移
      if ( s[right] in map ) { // 判断字符串是否为 t 中的字符串
        if (map[ s[right] ] < need[ s[right] ]) { // 判断是否符合累加条件
          count = count + 1;
        }
        map[ s[right] ] = map[ s[right] ] + 1;
      }
    }
    let temp = s.slice(left, right + 1); // 当前区间
    if ( count === t.length ) { // 当前为有效区间
      if (s[ left ] in map) { // 如果当前有效区间的最左侧字符为有效字符，说明当前区间不能再执行 left指针 右移进行压缩了
        result = (temp.length < result.length || result === '') ? temp : result; // 判断当前有效区间是否为更小的子串
        if (map[ s[left] ] === need[ s[left] ]) { // 判断是否符合累减条件
          count = count - 1;
        }
        map[ s[left] ] = map[ s[left] ] - 1;
      }
      left = left + 1; // left指针 右移，开始寻找下一个有效区间
      r = false; // 本次是 left指针 右移，所以 r = false
    }
    else { // 当前不是有效区间
      right = right + 1; // right指针 右移，继续增大区间，直到找到有效区间
      r = true; // 本次是 left指针 右移，所以 r = false
    }
  }
  
  return result;
};

```