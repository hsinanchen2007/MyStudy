这道题可以用合并区间的思路解决 可以看一下56题
假如abbabc这个字符串 a最后的index是3
当走到第一个b时,因为第一个b的位置小于3 所以更新区间的右边界为4
当走到c时，因为c的位置>right 所以将之前的区间放进list 并更新左区间的位置
```
class Solution {
    public List<Integer> partitionLabels(String S) {
        int[] last = new int[26];
        for(int i = 0; i < S.length(); i++)
            last[S.charAt(i) - 'a'] = i;
        
        List<Integer> list = new ArrayList<>();
        int left = 0;
        int right = last[S.charAt(0) - 'a'];
        for(int i = 1; i < S.length(); i++)
        {
            if(i > right)
            {
                list.add(right - left + 1);
                left = i;
            }
            right = Math.max(right, last[S.charAt(i) - 'a']);
        }
        list.add(right - left + 1);
        return list;
    }
}
```
