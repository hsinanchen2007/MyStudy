本题也是典型的滑动窗口，

之前在做**最小覆盖子串**和**找到字符串中所有字母异位词**两道题的时候，总结了一些方法，

和本题的套路是一模一样的，可以参考一下噢，

只是学习笔记，有什么不对的地方还希望各路大佬指出。

如果看懂这个套路，这道题就迎刃而解了。

[LeetCode学习笔记——最小覆盖串/字母异位词（Sliding Window)](https://blog.csdn.net/wangerxiao121223/article/details/105370705)

```
class Solution {
    public int[] shortestSeq(int[] big, int[] small) {
        int []res = new int[2];
        int []nores = {};
        HashMap<Integer, Integer> window = new HashMap<>();
        HashMap<Integer, Integer> need = new HashMap<>();
        int left = 0;
        int right = 0;
        int count = 0;
        int minlen = Integer.MAX_VALUE;
        for(int num : small)
            need.put(num, need.getOrDefault(num, 0) + 1);
        while(right < big.length) {
            int num1 = big[right];
            if(need.containsKey(num1)) {
                window.put(num1, window.getOrDefault(num1, 0) + 1);
                if(need.get(num1) == window.get(num1))
                    count++;
            }
            right++;
            while(count == need.size()) {
                if(right > 0 && right - left < minlen) {
                    res[0] = left;
                    res[1] = right - 1;
                    minlen = right - left;
                }
                int num2 = big[left];
                if(need.containsKey(num2)) {
                    window.put(num2, window.getOrDefault(num2, 0) - 1);
                    if((int)window.get(num2) < (int)need.get(num2))
                        count--;
                }
                left++;
            }
        }
        return minlen == Integer.MAX_VALUE ? nores : res;
    }
}
```
