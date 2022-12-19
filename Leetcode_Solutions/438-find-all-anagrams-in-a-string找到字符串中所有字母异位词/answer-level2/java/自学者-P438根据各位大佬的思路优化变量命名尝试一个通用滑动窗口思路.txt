### 解题思路
* 滑动窗口要滑动起来
* 学习字典索引

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        if (Objects.isNull(s) || s.length() == 0) {
            return Collections.emptyList();
        }
        List<Integer> result = new ArrayList<>();
        //由于都是小写字母，因此直接用26个长度的数组代替原来的HashMap
        int[] alphabeticCount = new int[26];
        int[] slideWindow = new int[26];
        int left = 0, right = 0;

        //用total检测窗口中是否已经涵盖了p中的字符
        int total = p.length();
        //统计目标串中各个字母存在的数量
        initAlphabeticCount(p, alphabeticCount);
        while (right < s.length()) {
            char charAtRight = s.charAt(right);
            int indexRight = charAtRight - 'a';
            if (targetContainsKey(alphabeticCount[indexRight])) {
                // 滑动窗口中增加一个元素
                slideWindow[indexRight]++;
                //增加了一个元素以后，判断一下该元素的数量是否满足目标串中要求的数量
                if (slideWindow[indexRight] <= alphabeticCount[indexRight]) {
                    //滑动窗口匹配一个以后，匹配数字增加，也就是total要减少一个
                    total--;
                }
            }
            //当前所有的数量全部被清零以后，也就是滑动窗口中的字符数量已经全部满足了要求
            while (validSlideWindow(total)) {
                if (right - left + 1 == p.length()) {
                    // 返回这些子串的起始索引
                    result.add(left);
                }
                char charAtLeft = s.charAt(left);
                int indexLeft = charAtLeft - 'a';
                if (targetContainsKey(alphabeticCount[indexLeft])) {
                    slideWindow[indexLeft]--;
                    if (slideWindow[indexLeft] < alphabeticCount[indexLeft]) {
                        //用total检测窗口中是否已经涵盖了p中的字符,增加1个打破滑动窗口条件
                        total++;
                    }
                }
                // 滑动窗口起始位置右移1位
                left++;
            }
            // 滑动窗口结束位置右移动1位
            right++;
        }
        return result;
    }

    private boolean validSlideWindow(int total) {
        return total == 0;
    }

    private boolean targetContainsKey(int i) {
        return i > 0;
    }

    private void initAlphabeticCount(String p, int[] needs) {
        for (char ch : p.toCharArray()) {
            needs[ch - 'a']++;
        }
    }   
}
```