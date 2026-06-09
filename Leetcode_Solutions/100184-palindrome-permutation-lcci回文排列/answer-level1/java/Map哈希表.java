题目描述的有问题，我开始以为只有大小写英文字母算入在内，如果是非字母就过滤掉，后老发现所有字符都算在内。
算法：创建一个Map，遍历字符串，统计字符串中每种字符出现的次数，若所有字符出现的次数都是偶数个 、或者仅有一种字符出现的个数是奇数个，那么可以构成回文。时间复杂度o(N)，空间复杂度o(N)。
```
public boolean canPermutePalindrome(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (char c : s.toCharArray()) {
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        int oddCount = 0;
        for (int num : map.values()) {
            if (num % 2 == 1) {
                ++oddCount;
            }
        }
        return oddCount <= 1;

    }
```
