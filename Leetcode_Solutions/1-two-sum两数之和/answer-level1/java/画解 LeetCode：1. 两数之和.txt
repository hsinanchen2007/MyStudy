
## 两遍哈希表

![WeChat Image_20190802194727.png](https://pic.leetcode-cn.com/78b7727706ce65ec506699d2f97adc68a10b9c48cc3f283c37f51f2488f7e854.png)

### 思路

* 标签：` 哈希表 `
* 「暴力法」时间复杂度高，因为差值要一一和其后元素比较，如果差值一次就能和其他所有元素比较，那么时间复杂度为 O(n)
* 可以利用哈希表的 contains() 实现此功能
* 因为需要返回索引，所以元素和索引要相关联，所以使用 Map 结构
* 因为要返回索引，假设索引作为 key，元素作为 value，**不能根据 value（元素）反推其 key（索引）**，所以元素作为 key，索引作为 value
* 虽然数组中元素可重复，重复元素作为 key 加入 map 时，**value（索引）更新，此时索引代表重复元素**。所以重复元素无影响
* 两遍哈希表，第一遍将数据存放到 map 中，第二遍使用 contains() 方法
* 时间复杂度：O(n)
* 空间复杂度：O(n)

### 代码
```Java []
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>(); // 引用对象使用 <Integer, Integer> 可指定存储类型
        for (int i = 0; i < nums.length; i++) {
            map.put(nums[i], i); // 元素作为 key，索引作为 value
        }
        for (int i = 0; i < nums.length; i++) {
            int key = target - nums[i];
            // map.containsKey(key) 相当于 map.keySet().contains(key)；
            // 利用 && 特性：如果 map.containsKey(key) 为 false，map.get(key) 将不执行，避免空指针异常；
            // map.get(key) != i: 索引不同，确保不是同一个元素
            if (map.containsKey(key) && map.get(key) != i) { 
                return new int[]{i, map.get(key)};
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
```
```JavaScript []
var twoSum = function (nums, target) {
    var map = new Map();
    for (let i = 0; i < nums.length; i++) {
        map.set(nums[i], i);
    }
    for (let i = 0; i < nums.length; i++) {
        let key = target - nums[i];
        if (map.has(key) && map.get(key) !== i) {
            return [i, map.get(key)];
        }
    }
};
```
### 画解
![WeChat Image_20190802194727.png](https://pic.leetcode-cn.com/639c635ae28d67db3d6f11e7488abb7eca5935e0f27e17c467e56336a4ddddf4-file_1564746699980)
## 一遍哈希表
### 思路
* 标签：` 哈希表 `
* 可将第一遍哈希省略，每次循环，将元素、索引存于 map，当前元素可与 **map 中已加入**的元素比较
* 时间复杂度：O(n)
* 空间复杂度：O(n)
### 代码
```Java []
class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int key = target - nums[i];
            if (map.containsKey(key)) { // 跟 map 中已加入元素比较，肯定不是同一个元素，所以不比较索引
                return new int[]{map.get(key), i}; // i在后
            }
            map.put(nums[i], i);
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
```
```JavaScript []
var twoSum = function (nums, target) {
    var map = new Map();
    for (let i = 0; i < nums.length; i++) {
        let key = target - nums[i];
        if (map.has(key) && map.get(key) !== i) {
            return [map.get(key), i];
        }
        map.set(nums[i], i);
    }
};
```
### 画解
* 请看灵魂画师牧码的 [画解](https://leetcode-cn.com/problems/two-sum/solution/jie-suan-fa-1-liang-shu-zhi-he-by-guanpengchn/)