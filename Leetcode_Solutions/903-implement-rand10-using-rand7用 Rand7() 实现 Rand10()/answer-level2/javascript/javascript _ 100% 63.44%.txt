 思路： 
1. 首先获取等概率的 1,2,3,4,5 (如果rand7()结果>5则抛弃重新来一次 根据对称性原理 1,2,3,4,5等概率)
2. 再以50%的概率是否加上5  这样可以得到等概率的1-10

```js
var rand10 = function() {
            // 等概率1-5
            let result = rand7()
            while(result>5) result = rand7()
            // 等概率1-6
            let temp = rand7()
            while(temp === 7) temp = rand7()
            return temp <= 3 ? result : result + 5
};
```