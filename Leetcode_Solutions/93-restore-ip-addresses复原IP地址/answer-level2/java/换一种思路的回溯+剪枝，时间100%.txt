一开始看到这道题，把题理解成解空间的话，一般会想到是一个有三个分叉的树，表示IP的下一段是1位，2位，3位，但是尝试写了一下，发现各种条件不太好处理，代码比较复杂。

后来考虑可以转换一下思路，把树改成二叉树，每个分支都表示在这位后是否要进行加点操作（是or否），然后通过合理的剪枝来限定解的搜索，这样代码就非常容易理解。
这里在条件限定上有几处优化：
1. L5，优化了对原字符串的条件限定
2. backTrace的入参包含目前累计的值，可以用作L23的判断条件
3. L12，如果放置了超过3个点，直接判断无效进行返回
4. L26，右边那串公式，就是 [chars余下的空间] >= [目前剩余dots所需最小空间] = 2 * [rest dots] + 1; 可以打印输出看到，这个剪枝的效果是比较明显的

代码如下：
```
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        char[] chars = new char[s.length() + 3];
        if (s.length() >= 4 && s.length() <= 12) {
            this.backTrace(result, 0, s, 0, chars, 0);
        }
        return result;
    }
    
    private void backTrace(List<String> result, int start, String s, int pos, char[] chars, int number) {
        if (pos > start + 3 || start == s.length() || pos == chars.length) {
            if (pos == start + 3 && start == s.length()) {
                result.add(new String(chars));    
            }
            return;
        }
        
        char c = s.charAt(start);
        chars[pos] = c;
        number = number * 10 + (c - '0');
        
        if (number < 256) {
            int dots = pos - start;
            // do not add dot
            if ((number != 0 || start == s.length() - 1) && (pos <= s.length() - 4  + (dots << 1))) {
                // System.out.println(String.format("do not add dot: %d, %d", start, pos));
                this.backTrace(result, start + 1, s, pos + 1, chars, number);
            }
            // add dot
            if (pos < chars.length - 2) {
                // System.out.println(String.format("add dot: %d, %d", start, pos));
                chars[pos + 1] = '.';
                this.backTrace(result, start + 1, s, pos + 2, chars, 0);
            }
        }
    }    
    
}
```
