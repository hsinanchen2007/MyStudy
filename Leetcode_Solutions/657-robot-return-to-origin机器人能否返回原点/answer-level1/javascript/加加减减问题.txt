### 解题思路
此处撰写解题思路
1.用两个变量表示 x y 轴, 右 x加1 上y加1  左,下减1, 看他最后 x和y是否都为0
![image.png](https://pic.leetcode-cn.com/d3efe9bed559ca718fd80947dc10270b1dad3ef7774440314be29221e8590fd5-image.png)

### 代码

```javascript
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
   let x = 0
   let y = 0 
   let list = moves.split('')
   list.forEach(item=>{
     switch(item){
        case 'R':
          x++
          break;
        case 'L':
          x--
          break;
        case 'U':
          y++
          break;
        case 'D':
          y--
          break;
     }
   })

   return x==0&&y==0
};
```

2.看字符串出现的 R和L, U和D 的次数是否相等, 这个解法时间比较久
![image.png](https://pic.leetcode-cn.com/704429fa5b4d247c1d96468cd3137f233f2baca1d23c7bef13093f8aa07b887c-image.png)

```javascript
var judgeCircle = function(moves) {
   let x = moves.split('R').length === moves.split('L').length
   let y = moves.split('U').length === moves.split('D').length
  
   return x&&y
};
```