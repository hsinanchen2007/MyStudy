## 一次for循环找出重复与缺失元素

### 解法一：HashMap + 求和法
正确的数组包含的是1到n共n个数字，根据题意，现在缺了一个数字并且另一个数字重复，需找出这两个问题数字。
求和法具体指：将正确的数组所有元素加和（即用求和公式将1到n求和），再将问题数组所有元素求和，这两个和作差后的结果是(missing-dup)，因此将这个差再加上dup，得到的就是missing。
用HashMap记录数组及其出现次数，用于求出重复元素，用一次for循环，就可以求出问题数组的和以及重复的元素，运用上述方法求解缺少的数字。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum = 0, dup = 0;
        int len = nums.length;
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i : nums)
        {
            sum += i;
            if(map.containsKey(i))  dup = i;
            else                    map.put(i, 1);
        }
        int missing = (1 + len) * len / 2 - (sum - dup);
        return new int[] {dup, missing};
    }
}
```

### 解法二：数组 + 求和法 
思路与解法一相同，只不过本解法用int[]数组来作为散列表，散列表大小为(n+1)，数组下标代表数字，存储的元素则为下标所代表的数字的出现次数。同理，通过循环利用散列表找出重复元素并求和，然后解出缺失的数字。
利用数组代替HashMap后，速度得到提升。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum = 0, dup = 0;
        int len = nums.length;
        int[] hash  = new int[len + 1];
        for(int i : nums)
        {
            sum += i;
            if(hash[i] == 1)    dup = i;
            else                hash[i] = 1;
        }
        int missing = (1 + len) * len / 2 - (sum - dup);
        return new int[] {dup, missing};
    }
}
```

### 解法三：数组 + 按位异或
由上述解法得到启发，既然可以用求和的方法，也可以尝试位运算的思路。之前的题解提到过，相同的数异或运算得到0，不同的数异或运算得到1，相当于不进位的加，不借位的减，成对出现的数字可以通过异或两两相消。
正确的数组为1到n
错误的数组为1到n，但缺少了一个元素，并且另一个元素重复。
显然，两个数组所有元素异或运算得到的结果就是 dup ^ missing
同上熟解法一样，利用数组作为散列表可以找出dup，missing也就迎刃而解了。

时间复杂度：O(n)。
空间复杂度：O(n)。

代码：

```java
class Solution {
    public int[] findErrorNums(int[] nums) {
        int sum = 0, dup = 0;
        int len = nums.length;
        int[] hash = new int[len + 1];
        for(int i = 0; i < len; i++)
        {
            int n = nums[i];
            if(hash[n] == 1)    dup = n;
            else                hash[n] = 1;
            sum = sum ^ (i+1) ^ n;
        }
        int missing = sum ^ dup;
        return new int[] {dup, missing};
    }
}
```