### 解题思路
+ 首先 `s`、`t`必须是相等的，
+ 对`s`、`t`进行分割，然后遍历，以`s`为基础， 逐个对比，
+ 每次遇到相同的则从`t`删除,
+ 最后`t`为0,则通过


### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
  if(s.length != t.length){
    return false;
  }
  let result = false;
  let sArr = s.split('');
  let tArr = t.split('');
  sArr.map((k)=>{
    let index = tArr.findIndex(u=>u==k);
    if(index>=0){
      tArr.splice(index,1);
    }
    return k;
  })
 
  return !tArr.length;
};
```