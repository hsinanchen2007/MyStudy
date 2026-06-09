别看名字起得这么玄乎（没有标题党的意思），只要有哈希表的基础知识，是很容易想到思路的。

这里「哈希」是 hash 的音译，意译是「散列」。

思路：

+ 分入一组的字符串的特征：字符以及字符的个数相等，但是顺序不同；
+ 这样的特征其实可以做一个映射，思想来源于哈希规则。这里要去除顺序的影响，那么我们就只关心每个字符以及它出现的次数；
+ 每个字符对应一个 ASCII 值，用 ASCII 值乘以字符出现的次数的和感觉上就能表征一组字符串，但是很容易想到，这里面会有重复的值；
+ 一个替代的做法是，把 ASCII 值 替换成为质数，于是这些数值一定不会有公约数，不在一组的数，它们的和一定不相等（也就是放在哈希表里，肯定不会被分在一个桶里）；
+ 所有输入均为小写字母，因此只需要做 26 个映射，这种映射可以通过数组实现。

（限于本人水平有限，这里的思路没有办法说得很清楚，也没有办法证明给大家看，只能说是想法通过测试得到验证。）

评论有朋友提到，这样计算出来的「哈希值」是有可能整型越界的，这一点是我一开始没有想到的。但是仔细算了一下，这里「消耗」最大的值就是字母 `z` ，它对应的 ASCII 码是 25（已经减去了偏移），它对应的质数最大是 101，如果全部使用 `z` 是最消耗值的，运行下面这段代码：

```java
System.out.println(Integer.MAX_VALUE / 101 / 25);
```

输出：850488。

因此，要产生溢出，输入字符至少长度要达到 850488 才可以。在这里认为不存在这种测试用例。


知识点复习：

+ 哈希表的底层就是数组；
+ 哈希函数；
+ 哈希冲突的解决办法：1、链接法；2、开放地址法；
+ 哈希表的扩容。

参考《算法导论》或者《算法 4》，初学的时候懂得意思，有个感性认知即可。


**参考代码**：

```Java []
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class Solution {


    public List<List<String>> groupAnagrams(String[] strs) {

        // 考察了哈希函数的基本知识，只要 26 个即可
        // （小写字母ACSII 码 - 97 ）以后和质数的对应规则，这个数组的元素顺序无所谓
        // key 是下标，value 就是数值
        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
                31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                73, 79, 83, 89, 97, 101};

        // key 是字符串自定义规则下的哈希值
        Map<Integer, List<String>> hashMap = new HashMap<>();
        for (String s : strs) {
            int hashValue = 1;

            char[] charArray = s.toCharArray();
            for (char c : charArray) {
                hashValue *= primes[c - 'a'];
            }

            // 把单词添加到哈希值相同的分组
            if (hashMap.containsKey(hashValue)) {
                List<String> curList = hashMap.get(hashValue);
                curList.add(s);
            } else {
                List<String> newList = new ArrayList<>();
                newList.add(s);

                hashMap.put(hashValue, newList);
            }
        }
        return new ArrayList<>(hashMap.values());
    }

    public static void main(String[] args) {
        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

        Solution solution = new Solution();
        List<List<String>> res = solution.groupAnagrams(strs);
        System.out.println(res);

        System.out.println((int) 'a');
    }
}
```