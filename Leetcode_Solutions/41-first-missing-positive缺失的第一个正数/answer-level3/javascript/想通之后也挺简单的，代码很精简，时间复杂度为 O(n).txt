### 解题思路
因为需要找正整数，所以可以巧用数组索引解决问题。
将所有正整数当作临时数组(临时数组初始化时为[1]，因为索引0不是正整数)的索引存放，然后再次遍历临时数组，如果当前索引下临时数组的值为undefined，则为缺省的那个正整数。
列如:
temp = [1];//初始化
nums = [1,3];
temp[1] = true;//这个true 可以是任意表达式为真的值
temp[3] = true;
遍历temp数组时，发现temp[2]为空，则缺省的正整数为2

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function (nums) {
    let temp = [1];
    nums.map(i=>{
        i > 0 && (temp[i] = true);
    });
    for(let i = 0; i <= temp.length; i++){
        if(!temp[i]){
            return i;
        }
    }
};
```