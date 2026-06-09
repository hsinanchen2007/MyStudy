### 解题思路
刚开始没想到使用while的方式，掉进了for的循环圈子里感觉不对
看了其他大神的评论之后想到了这种方法，和另一位大神不谋而合，我这算是借鉴版，
刚开始刷题水平不够，思路不够开阔

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function (candies, num_people) {
    // 定义一个数组长度为小朋友总数的数组并把每项都用0填充
    let arr = new Array(num_people).fill(0);
    // 定义一个初始值
    let num = 0;
    // 当糖果不够的时候才跳出循环
    while (candies > num) {
        // %能准确的拿到每个小朋友对应的下标
        arr[(num % num_people)] += ++num;
        candies -= num;
    }
    // 跳出循环之后把剩余的糖都分给最后一个小朋友
    arr[(num % num_people)] += candies;
    return arr;
};
```