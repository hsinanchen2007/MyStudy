### 解题思路
这一题和[984. 不含 AAA 或 BBB 的字符串](https://leetcode-cn.com/problems/string-without-aaa-or-bbb/)很像，只不过可用的字符换成了三个。

其实无论可用的字符有多少，思路都是一致的。我们可以将每一个可用字符对应的数字放到一个大根堆中(如果数字为0则字符不可用，不需要放到堆中)。

每次当我们拿到堆顶数字时，尽可能多地将数字对应的字符拼接到结果字符串上。这里题目要求结果字符串中不能出现连续三个相等的字符，所以我们每次尽可能地拼接两个相同的字符。

需要注意的是，每轮我们会从堆里选出两个数字，在第一个数字更新(减一或减二)后，如果第二个数字不是最大的，那么第二个数字对应的字符只能拼接一个。

以a = 5, b = 2, c = 0为例。第一轮我们选5和2，先将"aa"拼接到结果字符串上，a减2变为3。此时b并不是最大的数字，我们只能将一个'b'拼接到结果字符串上，否则就会得到错误的答案。

### 代码

```java
class Solution {
    class Char {
        int freq;
        char c;
        
        public Char(int f, char cc) {
            freq = f;
            c = cc;
        }
    }
    
    public String longestDiverseString(int a, int b, int c) {
        StringBuilder sb = new StringBuilder("");
        PriorityQueue<Char> queue = new PriorityQueue<Char>(new Comparator<Char>(){
            public int compare(Char i1, Char i2) {
                return i2.freq - i1.freq;
            } 
        });
        if (a > 0) {
            queue.offer(new Char(a, 'a'));    
        }
        if (b > 0) {
            queue.offer(new Char(b, 'b'));    
        }
        if (c > 0) {
            queue.offer(new Char(c, 'c'));    
        }
        while (queue.size() > 1) {
            Char first = queue.poll();
            if (first.freq >= 2) {
                sb.append(first.c + "" + first.c);
                first.freq -= 2;
            }
            else {
                sb.append(first.c);
                first.freq -= 1;
            }

            Char second = queue.poll();
            if (second.freq >= 2 && second.freq >= first.freq) { //这一步的判断是关键
                sb.append(second.c + "" + second.c);
                second.freq -= 2;
            }
            else {
                sb.append(second.c);
                second.freq -= 1;
            }
            if (first.freq > 0) {
                queue.offer(first);
            }
            if (second.freq > 0) {
                queue.offer(second);
            }
        }
        if (!queue.isEmpty()) {
            Char temp = queue.poll();
            if (sb.length() == 0 || temp.c != sb.charAt(sb.length() - 1)) {
                if (temp.freq >= 2) {
                    sb.append(temp.c + "" + temp.c);
                }
                else {
                    sb.append(temp.c);
                }
            }
        }
        return sb.toString();
    }
}
```