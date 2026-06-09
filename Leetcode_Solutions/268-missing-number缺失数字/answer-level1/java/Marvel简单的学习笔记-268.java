## 记录两种解法

### 解法一：求和公式
根据题意，给定数组就是0,1,2...n中删去一个数的集合。
显然，利用求和公式可以求出在删去一个数前，该序列所有元素之和。然后减去删去一个数后的序列和，得到的差就是缺失的数。

时间复杂度：O(n)。
空间复杂度：O(n)。

缺点：求和有溢出的风险。

代码：
```java
class Solution {
    public int missingNumber(int[] nums) {
        int sum = (1 + nums.length) * nums.length / 2;
        for(int i : nums)
            sum -= i;
        return sum;
    }
}
```

### 解法二：位运算
两种思想本质一样，都是通过与无缺失序列相消得到缺失数字。
按位异或（XOR），相当于一种不进位的加，不借位的减。0、1异或得1；1、1和0、0异或得0。即相同的两个数异或得0。
无缺失序列：0,1,2...nums.length。
缺失序列：数组各元素。
无缺失序列比缺失序列多一个元素，其余所有元素都能在缺失序列中找到相同元素，所以两个序列所有元素按位异或，除了多出来的那个元素，其他所有元素都能找到相同的另一个，两个相同的元素按位异或得到0。整个过程下来，按位异或得到的结果就是缺失元素。

时间复杂度：O(n)。
空间复杂度：O(1)。

代码：
```java
class Solution {
    public int missingNumber(int[] nums) {
        int res = 0;
        for(int i = 0; i < nums.length; i++)
            res ^= nums[i] ^ i;
        return res ^ nums.length;
    }
}
```