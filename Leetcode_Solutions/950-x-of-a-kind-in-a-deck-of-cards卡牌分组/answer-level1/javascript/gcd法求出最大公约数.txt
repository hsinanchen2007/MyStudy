### 解题思路
gcd最大公约数
做的时候因为用obj比较顺手
没去用map方法 想法是创建一个对象
把原数组中 
不同数字=键名
出现次数=键值
把键值取出来单独放在一个数组里面
然后通过循环求出这个数组的最大公约数 如果是大于1就说明成立
gcd = (a, b) => (b === 0 ? a : gcd(b, a % b))//公约数函数 gcd算法
### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
let gcd = (a, b) => (b === 0 ? a : gcd(b, a % b))
var hasGroupsSizeX = function(deck) {
    if(deck.length<=1){
        return false
    }
let obj={};
let arr=[];
let g=0;
for(let i=0;i<deck.length;i++){
   if(!obj[deck[i]]){
      obj[deck[i]]=1
   }else{
      obj[deck[i]]+=1
   }
}
for(var key in obj){
arr.push(obj[key])
}
arr.sort();
arr.forEach((item)=>{
    g=gcd(g,item)
})
return g>1;
};

```