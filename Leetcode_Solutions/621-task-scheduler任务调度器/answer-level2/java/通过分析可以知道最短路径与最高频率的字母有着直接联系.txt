通过分析可以知道最短路径与最高频率的字母有着直接联系
```
class Solution {
    public int leastInterval(char[] tasks, int n) {
        if(tasks.length==0) return 0;
        int ch[] = new int[256];
<!-- 统计字母出现的频率 -->
        for(char c : tasks){
            ch[c]++;
        }
<!-- 获取出现最多的次数 -->
        int max = Integer.MIN_VALUE;
        for(int i :ch){
            max =Math.max(max,i);
        }
<!-- 得到一共有几个字母都以最高频次出现 -->
        int  count=0;
        for(int i :ch){
            if(i==max) ++count;
        }
        return Math.max((n+1)*(max-1)+count,tasks.length);
    }
}
```
