### 解题思路
很头痛
![image.png](https://pic.leetcode-cn.com/e9d6b5665d6ba8c0cfa993b639a24482b2e3663b96de243c9f4d19286e074191-image.png)

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var letterCasePermutation = function(S) {
  S = S.toLowerCase()
  let list = []
  function fn(num, s){
    list.push(s)
    for(let i = num; i < s.length; i++){
      let str = s.slice(0,i) + s[i].toUpperCase() + s.slice(i + 1)
      fn(i + 1, str)
    }
  }
  fn(0,S)
  return [...new Set(list)]
};
```
``` js
//  S = 'aBc'
//  不管有无大写, 统一处理成小写的 得到 S = 'abc'

开始num = 0, s = 'abc': 

fn(0, 'abc') 
 
                   fn(2,'ABc')  => fn(3,'ABC')
fn(1, 'Abc') => {            
                   fn(3,'AbC')

fn(2, 'aBc') => fn(3, 'aBC')

fn(3, 'abC')

 // 因为中间会混杂些数字的情况, 所以最后去重处理         
```
执行顺序
![image.png](https://pic.leetcode-cn.com/93bf859f08774e998c5313c5facf26dd16d77b483d022565ba3b373d77d8b473-image.png)![image.png](https://pic.leetcode-cn.com/0e718e2f6d4fb5378fc75e6f9376fa90a7ee721fb42dfa9790d03eeca5732284-image.png)
