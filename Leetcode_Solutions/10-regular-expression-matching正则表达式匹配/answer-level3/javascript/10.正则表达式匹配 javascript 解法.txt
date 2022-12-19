思路：
观察可知s，p的比对有三种情况，第一种纯字符比较，第二种'.'与字符的比较，第三种是带有'*'的模式比较
1. 定义基础返回条件，p的长度为0时，s的长度为0则表示匹配，s的长度不为0则表示不匹配
2. 定义状态match，即为第一个字符的互相比较，如果相等或p[0]为'.'则为true
3. 当p没有模式的时候，我们根据match的状态进行返回，如果match为false，直接返回false，如果为true，那么进行下一步的判断getIsMactch(s.slice(1), p.slice(1)
4. 当p有模式的时候，有两种情况：一是s\*匹配0个字符，则进行getIsMactch(s, p.slice(2))，二是s\*匹配1个字符，递归下去，用来表示s\*匹配多个s\*,这样如果match为false，直接返回false，如果为true，那么进行getIsMactch(s.slice(1), p)。这两种只要一个能成立就够了
5. 4中这样的判断是为了避免'a\*a'这种测试用例的坑
```javascript []
var isMatch = function (s, p) {
  let getIsMactch = (s, p) => {
    //判断，如果传入p的长度为0，那么，必须s的长度也为0才会返回true
    if (p.length === 0) {
      return !s.length
    }
    //判断第一个字符是否相等
    let match = false
    if (s.length > 0 && (s[0] === p[0] || p[0] === '.')) {
      match = true
    }
    //p有模式的
    if (p.length > 1 && p[1] === "*") {
      //第一种情况：s*匹配0个字符
      //第二种情况：s*匹配1个字符，递归下去，用来表示s*匹配多个s*
      return getIsMactch(s, p.slice(2)) || (match && getIsMactch(s.slice(1), p))
    } else {
      return (match && getIsMactch(s.slice(1), p.slice(1)))
    }
  }
  return getIsMactch(s, p)
};
```
![image.png](https://pic.leetcode-cn.com/2819a5d12ea039507a8059f991bb4e0cbd70753ea3702aa812640e0971ce3f51-image.png)


代码：[快乐动起来老师的算法课](https://coding.imooc.com/lesson/315.html#mid=22127)