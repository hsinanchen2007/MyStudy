### 解题思路
这题给的测试用例真的刁钻，错了挺多次的，就差对每个用例if-return了（其实就是自己太菜了，手动狗头。。。）

先讲特殊用例
1.pattern.lenth() == 0 这时如果value.length() == 0 自然return true 否则 return false
2.value.length() == 0 这时如果仅有a或者仅有b 则return true(还有一种情况即a和b都为0，与第一种情况重合) 否则 return false

一般用例
即pattern和value均不为0
1.一般用例的特殊情况，即pattern中仅有a(b)，这时我们直接用value.length() / (count_a + count_b)拿到对应单个字符匹配的长度，再用substring拿到字符串，再用这个字符串依次匹配整个value字符串，全部equals则return true，否则return false
注意：这里如果value字符串为奇数，而pattern为偶数，肯定匹配不上，所以为了加速匹配直接return false
2.一般用例的一般情况，即pattern啥都有，这时我们需要拿到a，b的所有匹配模式，再对value进行匹配
想到暴力，即外层pattern_a_length 0 -> value.length(),内层pattern_b_length 0 -> value.length()，这时再判断是否匹配，这种方式过于暴躁，加上后面检测匹配的过程就n3次方了
所以我们想到匹配需要匹配整个字符串，所以我们先要计算下pattern中有多少a和b，再用value.length()去除，就能得到a和b所能匹配的最达长度，之后在外层pattern_a_length 0 -> value.length() / count_a,内层pattern_b_length自然唯一确定了(value.length() - count_a * pattern_a_length) / count_b，这里仍然可以对整体长度和a,b匹配长度总和进行比较，目的自然就是加速

解决了思路，剩余的遍历就完了

### 代码

```java
class Solution {
    public boolean patternMatching(String pattern, String value) {
        if(pattern.length() == 0) {
            if(value.length() == 0) return true;
            return false;
        }

        int count_a = 0;
        int count_b = 0;
        for(int i = 0; i < pattern.length(); i++) {
            if(pattern.charAt(i) == 'a') count_a++;
            else count_b++;
        }

        if(value.length() == 0) {
            if(count_a != 0 && count_b != 0) return false;
            return true;
        }

        int pattern_pos = 0;
        if(count_a == 0 || count_b == 0) {
            String patternString = value.substring(0, (value.length() / (count_a + count_b)));
            if(patternString.length() * (count_a + count_b) != value.length()) return false;
            int patternStringLength = patternString.length();
            for(int i = 0; i < value.length(); i += patternStringLength)
                if(! value.substring(i, i + patternStringLength).equals(patternString)) return false;
            return true;
        }

        int pattern_a_length = 0;
        int pattern_b_length = 0;
        String[] res = new String[2];
        int max_pattern_a = value.length() / count_a;
        for(; pattern_a_length <= max_pattern_a; pattern_a_length++) {
            Arrays.fill(res, "");
            pattern_b_length = (value.length() - count_a * pattern_a_length) / count_b;
            if(pattern_b_length * count_b + count_a * pattern_a_length != value.length()) continue;
            pattern_pos = 0;
            int i = 0;
            for(; i < pattern.length(); i++) {
                char ch = pattern.charAt(i);
                if(ch == 'a') {
                    if(pattern_a_length != 0 && res[0].equals("")) res[0] = value.substring(pattern_pos, pattern_pos + pattern_a_length);
                    else if(pattern_pos + pattern_a_length > value.length()
                            || ! value.substring(pattern_pos, pattern_pos + pattern_a_length).equals(res[0])) break;
                    pattern_pos += pattern_a_length;
                }
                else {
                    if(pattern_b_length != 0 && res[1].equals("")) res[1] = value.substring(pattern_pos, pattern_pos + pattern_b_length);
                    else if(pattern_pos + pattern_b_length > value.length()
                            || ! value.substring(pattern_pos, pattern_pos + pattern_b_length).equals(res[1])) break;
                    pattern_pos += pattern_b_length;
                }
                if(pattern_a_length != 0 && pattern_b_length != 0 && res[0].equals(res[1])) break;
            }
            if(i == pattern.length()) return true;
        }

        return false;
    }
}
```