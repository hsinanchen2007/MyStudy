### 解题思路
首先，除去最后一个不知数量的节点，前面就是一个等差数列，求出可以以等差的形式分发多少次
>n(n+1)/2<=candies
>完全平方公式得出   
`let times = Math.floor((Math.sqrt(1 + 8 * candies, .5) - 1) / 2)` 
![完全平方公式.PNG](https://pic.leetcode-cn.com/1b54ed2a59ccfe28ce408d5c28d9c5f4f1caac92e63430e41a72cf722a945c71-%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E5%85%AC%E5%BC%8F.PNG)
因为times>=0,所以右边括号内是一定大于零的，以至于左边的就一定要小于等于零。
`let residue = candies - (times * (times + 1)) / 2`
residue是残余的最后一个给与多少，值的范围0~times
num是获取能够分发多少完整的一轮，more是剩余的。

每一个的糖果数是：部分一：（行数\*（索引+1）+行数\*（行数-1）/2）这是完整一轮行数就是num
                部分二： 行数\*人数+索引+1
两部分相加就是每个人应得的糖果数，最后将剩余的糖果数 residue 给最后一个 arr[any]+=residue


### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function (candies, num_people) {
    let times = Math.floor((Math.sqrt(1 + 8 * candies, .5) - 1) / 2)
    let residue = candies - (times * (times + 1)) / 2
    let more = times % num_people;
    let any = more;
    let num = (times - more) / num_people;
    let arr = [];
    for (let i = 0; i < num_people; i++) {
        arr[i] = ((i + 1) * num + (num * (num - 1)) * num_people / 2) || 0
        if (more > 0) {
            arr[i] += num * num_people + i + 1;
            more--;
        }
    }
    arr[any] += residue;
    return arr;
};
```