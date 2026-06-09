// ### 解法

// ```java
	public String generateTheString(int n) {
        StringBuilder sb = new StringBuilder();
        if (n % 2 == 0) {
            for (int i = 0; i < n - 1; i++)
                sb.append('a');
            sb.append('b');
        } else {
            for (int i = 0; i < n; i++)
                sb.append('a');
        }
        return sb.toString();
    }
// ```

// 思路分析：

// * 只需要找到满足条件的一个字符串。条件是：字符串中的每一个字符，出现次数都是奇数。即没有限定要有几个字符，也没有限定每个字符至少至多能出现几次。
// * 那么找最简单的越方便，如果给定的n是奇数，那么我只用一个小写字母构成该长度的字符串就满足题意。如果n是偶数，那么我就用一个小写字母构成n-1位，第n位选另外一个小写字母也满足了题意。
// * 为了避免频繁的字符串拼接，使用`StringBuilder`类。
// * 时间复杂度是$O(n)$的，空间复杂度也是$O(n)$。

// 运行结果：执行时间1ms。

// 更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖