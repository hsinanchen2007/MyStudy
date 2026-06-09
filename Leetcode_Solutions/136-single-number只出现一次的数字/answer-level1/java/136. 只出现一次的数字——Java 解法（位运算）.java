## 解题思路

题目有几个关键点：

* 除了元素 X 只出现一次，其他元素都出现两次
* 题目要求算法具有线性时间复杂度

如果遍历一次就能找到只出现一次的元素呢？

**利用位运算 ^ 异或的特点**。

## 解题方式

^ 异或有两个特点：

**两个相同的元素异或结果为 0 ，而 0 和任何值 X 异或结果都是 X**

即：

```
A ^ A = 0

0 ^ B = B
```

**异或具有自反性**

即：
```
A ^ B ^ A = B
```

so：
```
public int singleNumber(int[] nums) {

        int result = nums[0];
        for (int i = 1; i < nums.length; i++) {
            result = result ^ nums[i];
        }

        return result;
    }
```


