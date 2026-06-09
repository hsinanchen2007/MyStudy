### 解题思路
参考标准答案中的解法，暴力法就不说了，大家应该都会。这里只说用遍历哈希表实现的方法。
因为在JS中没有原生哈希表的概念，所以我们在这里借用Object类型来模拟哈希表。
先建立一个Object来初始化哈希表，然后向其中导入数组作为属性，使得哈希得以实现。


### 代码
<br/>
#### 遍历2遍哈希表

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

const twoSum = (nums,target) => {
    let map = {}; //初始化哈希表

    for(let i=0;i<nums.length;i++) {
        map[nums[i]] = i; //将数组导入到哈希表
    }

    for(let i=0;i<nums.length;i++) {
        const complement = target - nums[i];

        //数据存在于哈希表且数据索引不与当前索引值相同
        if(map.hasOwnProperty(complement) && map[complement] !== i) { 
            return [i,map[complement]]; //输出当前索引和哈希表对应索引
        }
    }
}
```
时间复杂度O(n)，空间复杂度O(n)，执行时间在60-70ms左右。
<br>
#### 遍历1遍哈希表

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

const twoSum = (nums,target) => {
    let map = {}; //初始化哈希表

    for(let i=0;i<nums.length;i++) { //遍历数组
        const complement = target - nums[i];

        //在导入数组的同时检查是否已经包含目标元素
        if(map.hasOwnProperty(complement) && map[complement] !== i) { 
            return [i,map[complement]]; //输出当前索引和哈希表对应索引
        }
        //若没有包含目标元素，则导入数组元素，继续循环
        map[nums[i]] = i;
    }
}

```
时间复杂度O(n)，空间复杂度O(n)，执行时间在50-60ms左右。
<br>
### 希望能帮到有需要的人☺