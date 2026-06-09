### 解题思路
学习自大佬
简单做下笔记
--------
输入的是二进制无符号数，因此使用位逻辑运算符
### 方法1：最后一位数与1做逻辑与运算 统计结果
**步骤**：
1. 初始化返回值res
2. while循环下，当n不为0
    2.1. n与1做逻辑与运算，即最后一位数与1做逻辑与运算，结果累加存入res
    2.2. n右移一位
   直至n为0（遍历完）
3. 返回res

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int res = 0;
        while(n != 0){    
            //方法1
            res += n & 1;
            n >>>= 1;
        }
        return res;
    }
}
```
说明：n中的每一位都和1做逻辑与运算并将每个位的结果累加到res中，从而达到统计个数的目的
时间复杂度：O(logN)  即为n中的位数
空间复杂度：O(1) 变量

### 方法2：n &（n-1）统计1的个数
**步骤**：
1. 创建返回值res
2. while循环下，当n不为0
    2.1. n与n-1做逻辑与运算（【n-1 本质是使其每次的最右边的1变为0，其右边全变为1】，做完运算后的结果赋值给n）
    2.2. res++
3. 返回res


### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int res = 0;
        while(n != 0){
            n &= (n - 1);
            res++;
        }
        return res;
    }
}
```
说明：此方法利用（n-1）直接定位到n中1的位置，相互做逻辑与运算。无需一个个遍历
时间复杂度：<=O(N)  取决于1的个数，因此<=n
空间复杂度：O(1)