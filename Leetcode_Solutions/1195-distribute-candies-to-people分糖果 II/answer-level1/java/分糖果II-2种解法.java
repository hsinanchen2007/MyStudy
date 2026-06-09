>欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
>几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(candies ^ 0.5)。空间复杂度是O(1)。

执行用时：1ms，击败96.95%。消耗内存：33.7MB，击败100.00%。

```java
public class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int[num_people];
        int index = 1;
        for (int i = 0; ; i++) {
            if (candies <= index) {
                result[i % num_people] += candies;
                break;
            } else {
                result[i % num_people] += index;
                candies -= index++;
            }
        }
        return result;
    }
}
```

# 解法二：找规律

有candies颗糖果，按题述规则分配给num_people个小朋友，假设能够分配n轮，分配结果如下（其中last_remain为不足以分配给最后一个小朋友的剩余糖果数量）：

第一轮：1, 2, 3, 4, ..., num_people
第二轮：1 + num_people, 2 + num_people, 3 + num_people, 4 + num_people, ..., 2 \* num_people
第三轮：1 + 2 \* num_people, 2 + 2 \* num_people, 3 + 2 \* num_people, 4 + 2 \* num_people, ..., 3 \* num_people
...
第(n - 1)轮：1 + (n - 2) \* num_people, 2 + (n - 2) \* num_people, 3 + (n - 2) \* num_people, 4 + (n - 2) \* num_people, ..., (n - 1) \* num_people
第n轮：1 + (n - 1) \* num_people, 2 + (n - 1) \* num_people, 3 + (n - 2) \* num_people, ..., last_remain

如何根据candies和num_people计算得到n的值呢？

当candies刚好能分满n轮时，有如下关系：

candies = (1 + n \* num_people) \* n \* num_people / 2

由上式可计算出：

n = (((1 + 8 \* candies) ^ 0.5) - 1) / (2 * num_people)

当candies无法满足刚好能分满n轮的条件时，此时得到的n表明candies能够分满n轮但是还会有剩余remain，由于该remain的存在，还需要再进行一轮分配，但该轮分配无法圆满完成，在分配中途会由于糖果数量不足而退出。

时间复杂度是O(num_people)。空间复杂度是O(1)。

执行用时：0ms，击败100.00%。消耗内存：37MB，击败5.27%。

```java
public class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int[num_people];
        int turns = (int) ((Math.sqrt(1 + 8 * (long) candies) - 1) / (2 * num_people)),
                remain = candies - (1 + turns * num_people) * turns * num_people / 2;
        for (int i = 0; i < num_people; i++) {
            int tmp = Math.min(remain, i + 1 + num_people * turns);
            result[i] = (i + 2 + (turns - 1) * num_people + i) * turns / 2 + tmp;
            remain -= tmp;
        }
        return result;
    }
}
```