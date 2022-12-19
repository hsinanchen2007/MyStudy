### 解题思路
其实解出来的并不是唯一答案,

    I  D  I  D        长度为4  得到一个 [0,1,2,3,4]
    0  4  1  3  2

    D I I I D D      长度为6   得到一个 [0,1,2,3,4,5,6]
    6 0 1 2 5 4 3
    
   这种解法得出的答案符合题目要求,通过观察可以发现用代码的想法 可以这样: 

   拿到字符串了 得到一个长度, 即得到一个[0,1 ... n]的数组,  

   题目的要求是: I 对应的 的那一项的值小于 下一项的值, D对应的 那一项的值 大于下一项的值,

   所以我们可以一碰到D 就从就给它最大值, 第二次碰到D 就给他最大值-1.... ,以此类推碰到I 的就给他最小值, 第二次碰到I 就给它最小值-1.....

   这里的 最小值 最大值 就是根据字符串长度获取到的 递增数组 中的首尾,
### 代码

![image.png](https://pic.leetcode-cn.com/b96b6598a2b5e2fbd6de72a167b226cb46facc230d4e05f46af558487a3522db-image.png)

```javascript
/**
 * @param {string} S
 * @return {number[]}
 */
  var diStringMatch = function(S) {
    let I = 0,D = S.length;
    return S.split('').map(item=>{
      return item==='I'? I++ : D--
    }).concat([I])
};
```

这种解法比较容易理解:

![image.png](https://pic.leetcode-cn.com/125ac0e407c55ee7f7fcc19d367ffd84376d0e619fe37086b398dbeff028e436-image.png)

```js
var diStringMatch = function(S) {
  let nums = []
  let I = 0, D = S.length;
  for(let i=0;i<=S.length;i++){
    if(S[i]==='I'){
      nums.push(I)
      I++
    }else{
      nums.push(D)
      D--
    }
  }
  return nums
};
```

根据最开始的想法写出了下面这个,写复杂了

耗时太恐怖了

![image.png](https://pic.leetcode-cn.com/ced142255e2202091eb0cf087973677bc480c4e4d80905080c9d0218c5da97d3-image.png)


```js
var diStringMatch = function(S) {
  let nums = []
  for(let j=0;j<=S.length;j++){
    nums.push(j)
  }
  let arr = []
  while(S.length>0){
    let aa = nums
    let a = S.charAt()
    S = S.substr(1)
    if(a==='I'){
      let ind = nums.indexOf(Math.min(...nums))
      arr.push(Math.min(...nums))
      nums.splice(ind,1)
    } else {
      let ind = nums.indexOf(Math.max(...nums))
      arr.push(Math.max(...nums))
      nums.splice(ind,1)
    }
  }
  return arr.concat(nums)
};
```
