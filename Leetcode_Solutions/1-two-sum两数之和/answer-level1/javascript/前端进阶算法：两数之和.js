// ### 解题思路

// - 初始化一个 map = new Map() 
// - 从第一个元素开始遍历 nums 
// - 获取目标值与 nums[i] 的差值，即 k = target - nums[i] ，判断差值在 map 中是否存在
//   - 不存在（ map.has(k) 为 false ） ，则将 nums[i] 加入到 map 中（key为nums[i], value为 i ，方便查找map中是否存在某值，并可以通过 get 方法直接拿到下标）
//   - 存在（ map.has(k) ），返回 [map.get(k), i] ，求解结束
// - 遍历结束，则 nums 中没有符合条件的两个数，返回 []

// 时间复杂度：O(n)

// ### 代码

// ```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let map = new Map()
    for(let i = 0; i< nums.length; i++) {
        let k = target-nums[i]
        if(map.has(k)) {
            return [map.get(k), i]
        }
        map.set(nums[i], i)
    }
    return [];
};
// ```


// ### 认识更多的前端道友，一起进阶前端开发

// 前端算法集训营第一期免费开营啦🎉🎉🎉，免费哟！

// 在这里，你可以和志同道合的前端朋友们（800+）一起进阶前端算法，从0到1构建完整的数据结构与算法体系。

// 在这里，瓶子君不仅介绍算法，还将算法与前端各个领域进行结合，包括浏览器、HTTP、V8、React、Vue源码等。

// 在这里，你可以每天学习一道大厂算法题（阿里、腾讯、百度、字节等等）或 leetcode，瓶子君都会在第二天解答哟！

// 更多福利等你解锁🔓🔓🔓！

// 扫码关注公众号「前端瓶子君」内回复「算法」即时加入😊😊😊
// ![](https://pic.leetcode-cn.com/0693e3578144b3f79b70f3e98fdac525ff6c859af2a1e1e8b8da8b81a0e1e6cb.png)
