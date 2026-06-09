
本题和LeetCode47题一样，大家可以参考里面详细带图解的题解。

LeetCode46题是不带重复的全排列，LeetCode47： 带重复的全排列

> 本题难点如何去重？ —— 回溯剪枝

**对于无重复值的情况**
把第一个字符与后面每一个字符交换，获得一个排列；然后固定第一个字符，递归求后面的字符串组合。
> 这个都很简单，我想大家也都理解

**假如有重复值呢？**
例如abb，第一个字符与后面两个字符交换得bab，bba。然后abb中第二个字符和第三个字符相同，就不用交换了。但是对 bab，第二个字符和第三个字符不同，则需要交换，得到 bba。由于这里的bba和开始第一个字符与第三个字符交换的结果相同了，因此这个方法不行。

解决办法：对 abb，第一个字符a与第二个字符b交换得到 bab，然后考虑第一个字符与第三个字符交换，此时由于第三个字符等于第二个字符，所以第一个字符就不再用与第三个字符交换了。再考虑bab，它的第二个字符与第三个字符交换可以解决bba。此时全排列生成完毕！

修改的策略：第一个字符起，每个字符分别与它后面的字符交换，如果后面的字符中有重复的字符，那么第一个字符仅与其中的**一个**进行交换，跳过其他重复的。

如何判断重复？在每次递归中，都设置一个hash，记录交换过的字符，下次再遇到的时候，就跳过去。
```java
private void backtracking(char[] ch, int start, int end, LinkedList<String> ret) {
        if (start == end) {
            ret.add(new String(ch));
            return;
        }
        char temp;
        boolean[] used = new boolean[256];
        for (int i = start; i < end; i++) {
            // if(i > start && ch[i] == ch[start]) continue; 
            if (used[ch[i]]) continue;
            used[ch[i]] = true;
            swap(start, i);
            backtracking(ch, start+1, end, ret);
            swap(start, i);
        }
}
```
这是我的[LeetCode分类题解](https://github.com/caipengbo/LeetCode)（每日更新, issue内有总结），和我一起每日刷题吧！