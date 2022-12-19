
![Screenshot from 2020-03-08 10-20-44.png](https://pic.leetcode-cn.com/872c57fe9fefff822feaaa862ad2b9d2bd1bd2b10061890b16c2cadcc8895fdc-Screenshot%20from%202020-03-08%2010-20-44.png)

这道题方法还是很明显的，首先统计每个字符出现的次数，然后判断是否符合下面的两种情况之一：
1. 每个字符出现的次数为偶数；
2. 有且只有一个字符出现的次数为奇数。

如果满足，则重排之后可以构造出回文串。
所以，可以使用哈希表来存次数，但是更简单的方法是**直接使用数组作为哈希，字符作为索引**（数组下标）。

考虑到字符不一定是字典中的单词，所以哈希数组可以设置大一点（256个）。

```java
class Solution {
    public boolean canPermutePalindrome(String s) {
        if(s == null || s.length() <= 1) {
            return true;
        }
        
        int[] times = new int[256];
        // 统计字符出现的次数
        for(int i=0;i<s.length();i++) {
            times[s.charAt(i)]++;
        }
        return allEvenTimes(times) || oneOddTimes(times);
    }
    
    // 全部都出现偶数次
    private boolean allEvenTimes(int[] times) {
        for(int t : times) {
            if((t & 1) == 1) {
                return false;
            }
        }
        return true;
    }
    
    // 只有一个字符出现奇数次
    private boolean oneOddTimes(int[] times) {
        int odd = 0;
        for(int t : times) {
            if((t & 1) == 1) {
                odd++;
            }
        }
        return odd == 1;
    }
}
```

