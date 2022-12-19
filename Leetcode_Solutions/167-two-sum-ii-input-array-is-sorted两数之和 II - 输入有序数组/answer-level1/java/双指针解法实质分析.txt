## 题解思路
 https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leetco/
 官方题解使用双指针解法，但是没有解释为什么双指针好使。
 https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/solution/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/
 这个解法解释了为什么双指针好使，但是解释的还是有些不够直观.
 
 双指针解法在很多场景下都好使，尤其针对排序的数据效果比较好。以本题为例，对于一个排序的的数组就是双指针的适用场景。分析如下：

 双指针首先设定头尾指针：array[headIndex] 和array[tailIndex]，本地是为了求两个指针相加为target，那么问题变成为什么当array[headIndex]+array[tailIndex] > target的时候，tailIndex--不会把正确的解跳过去。

 以 【1，3，4，6，7，10，12】为例，target为10，我们可以看到答案组合为{3,7}{4,6}，最开始指针指向是{1,12}，那么需要tailIndex--，变成{1, 10}，实际上我们来看tailIndex--的含义是什么，以例子为例，开始的headIndex[0]（这个记为headIndex为0的时候，下文一样记录），tailIndex[6]，这时候tailIndex--让tailIndex变成了5，实际上就是把tailIndex[6]与headIndex[1..5](表示分别是headIndex 1到5的5个取值)的组合全部跳过去了（因为不可能有headIndex[1..5]与tailIndex[6]的组合了，headIndex[0]与tailIndex[6]已经>target了，headIndex[1..5]比headIndex[0]，那么其与tailIndex[6]一定> target，肯定不是有效解，可以直接跳过），继续{1,10} > 10，继续tailIndex--为{1, 7} < target，进行headIndex++变成了{3, 7}，headIndex++的含义就是跳过head[0] 与 tailIndex[1..4]的组合（同样head[0]与tailIndex[5]已经<target了，tailIndex[5]比tailIndex[1..4]大，那么head[0]与tailIndex[1..4]的组合都是<target，也一定不是有效解，可以直接跳过）。

其实双指针就相当于快速进行判断跳过很多无效解而已，但是不跳过可能解。
## 执行结果
![image.png](https://pic.leetcode-cn.com/c58df2092f9b9ff779068be0b590922584e8288b1c0a1efde885694e948217d3-image.png)

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        int tailIndex = numbers.length - 1;
        int headIndex = 0;
        while (tailIndex > headIndex) {
            int sum = numbers[headIndex] + numbers[tailIndex];
            if (sum == target) {
                /**
                 * index不是从0开始，所以+1
                 */
                result[0] = headIndex + 1;
                result[1] = tailIndex + 1;
                break;
            }
            if (sum > target) {
                tailIndex--;
            } else {
                headIndex++;
            }
        }

        return result;
    }
}
```