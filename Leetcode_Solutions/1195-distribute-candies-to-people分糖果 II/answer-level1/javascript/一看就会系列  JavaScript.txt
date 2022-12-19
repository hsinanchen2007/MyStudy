### 解题思路

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let childrens = new Array(num_people).fill(0);//初始所有小朋友获得糖果情况
    const allChildrensNum = childrens.length - 1;//最后一个小朋友的位置
    let nowCandies = 1;//当前发糖果的数量
    let boy = 0;//当前获得糖的小朋友
    while(candies !== 0) {//循环直到我们没有糖果
        candyNum = (candies >= nowCandies) ? nowCandies : candies;//此次发糖果的数量
        candies -= candyNum;//总糖果数减少
        childrens[boy] += candyNum;//当前小朋友获得糖果
        boy = (boy === allChildrensNum) ? 0 : boy + 1;//寻找下一个小朋友的位置
        nowCandies ++;//当前发糖果的数量加一
    }
    return childrens;//返回所有小朋友获得糖果的情况
};
```