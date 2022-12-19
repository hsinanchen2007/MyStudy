![image.png](https://pic.leetcode-cn.com/8fbe9d0d7e7f15151aaa3aba35dc21f4c56567293f1a0d497a3ef3e429a27207-image.png)

### 解题思路
见代码
### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 * 递归
 */
var countAndSay = function(n) {
    if(n==1) return '1';
    let str =arguments.callee(n-1);   //递归调用
    let arr =str.match(/(\d)\1*/g);    //得到所有的数组
    let res ='';
    arr.forEach((cur,index)=>{
        res += cur.length +cur[0];
    })
    return res;
};
```