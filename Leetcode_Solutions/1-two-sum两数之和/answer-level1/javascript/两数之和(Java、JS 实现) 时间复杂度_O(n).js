 #### 解题思路：
**方法一**
 1. 暴力法

- 使用两层循环，外层循环计算当前元素与 $target$ 之间的差值，内层循环寻找该差值，若找到该差值，则返回两个元素的下标。
- 时间复杂度：$O(n^2)$。

```java [-Java]
class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int dif = target - nums[i];
            // j = i + 1 的目的是减少重复计算和避免两个元素下标相同
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == dif){
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
            }
        }
        return res;
    }
}
```

 2. 利用 $HashMap$ 减少查询时间

- 在暴力法中，内层循环查找差值很浪费时间，那么如何减少查询时间呢？利用 $HashMap$ 就可以减少查询时间。
- 使用一层循环，每遍历到一个元素就计算该元素与 $target$ 之间的差值，然后到 $HashMap$ 中寻找该差值，如果找到，则返回两个元素在数组 $nums$ 的下标，如果没有找到，则将当前元素存入 $HashMap$ 中 $(Key: nums[i], Value: i)$ 。
- 时间复杂度：$O(n)$。

```java [-Java]
class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int[] res = new int[2];
        for (int i = 0; i < nums.length; i++) {
            int dif = target - nums[i];
            if (map.get(dif) != null) {
                res[0] = map.get(dif);
                res[1] = i;
                return res;
            }
            map.put(nums[i],i);
        }
        return res;
    }
}
```

**方法二**

1. 暴力法

- 使用两层循环，外层循环计算当前元素与 $target$ 之间的差值，内层循环寻找该差值，若找到该差值，则返回两个元素的下标。
- 时间复杂度：$O(n^2)$。

```javascript [-JS]
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for (var i = 0; i < nums.length; i++) {
        var dif = target - nums[i];
        // j = i + 1 的目的是减少重复计算和避免两个元素下标相同
        for (var j = i + 1; j < nums.length; j++) {
            if(nums[j] == dif)
                return [i,j];
        }
    }
};
```

2. 利用数组减少查询时间

- 在暴力法中，内层循环查找差值很浪费时间，那么如何减少查询时间呢？利用数组就可以减少查询时间。
- 使用一层循环，每遍历到一个元素就计算该元素与 $target$ 之间的差值 $dif$，然后以 $dif$ 为下标到数组temp中寻找，如果 `temp[dif]` 有值(即不是 $undefined$)，则返回两个元素在数组 $nums$ 的下标，如果没有找到，则将当前元素存入数组 $temp$ 中(下标: $nums[i], Value: i$) 。
- 时间复杂度：$O(n)$。

```javascript [-JS]
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var temp = [];
    for(var i=0;i<nums.length;i++){
        var dif = target - nums[i];
        if(temp[dif] != undefined){
            return [temp[dif],i];
        }
        temp[nums[i]] = i;
    }
};
```
