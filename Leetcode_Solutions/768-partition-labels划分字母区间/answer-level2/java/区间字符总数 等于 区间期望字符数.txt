该方法与官方解法类似, 但是比官方解法更复杂一点.


# 思路

首先, 遍历字符串, 统计每个字符出现的次数.

然后使用双指针滑动窗口. 滑动窗口中所有字符的期望总数是滑动窗口中各个字符的字符总和. 
当滑动窗口大小与期望总和相等时, 表明该滑动窗口可以称为一个有效的划分.


# 代码
```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        if( S == null || S.equals("")) {
            return new ArrayList<>();
        }
        
        // 统计字符串中各个字符的个数
        char[] arr = S.toCharArray();
        int[] map = new int[26];
        for(char c : arr) {
            map[c- 'a'] += 1;
        }

        List<Integer> result = new ArrayList<>();

        int left = 0;
        int n = arr.length;
        int expect = 0;

        Set<Character> winChars = new HashSet<>();

        for(int i=0; i<n; ++i) {
            // 统计滑动窗口中所有字符总次数之和
            // 这里使用了 HashSet 来避免对同一字符的多次统计
            if(!winChars.contains(arr[i])) {
                winChars.add(arr[i]);
                expect += map[arr[i] - 'a'];
            }

            // 滑动窗口的大小 与 期望字符总和相同
            // 表明该滑动窗口是一个有效划分
            if(i - left + 1 == expect) {
                result.add(expect);
                expect = 0;
                left = i + 1;
                winChars.clear();
            }
        }

        return result;
    }
}
```

