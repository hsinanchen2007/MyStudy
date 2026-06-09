这个题目是求转动的最少次数，很明显是求最优解，而最优解通常采用BFS，知道是BFS就很简单了，先把`0000`填入，弹出，判断转动一次是否能访问，如果能访问，则添加。

但是注意到，这题目如果单纯使用BFS的话虽然能解，但是速度估计会有点慢。广度优先搜索的搜索空间大小依赖于每层节点的分支数量，而在这个题目中，每次转动差不多增加8个数字，很明显，这个增长有点疯狂。

如果使用两个同时进行的广搜可以有效地减少搜索空间，一边从`0000`开始，一边从`target`开始，每次我们都找数目较少的进行，如果两边访问了同一节点，说明可以从`0000`达到`target`。

```
class Solution {
    public static int openLock(String[] deadends, String target) {
        HashSet<String> start = new HashSet<String>();//开始端
        HashSet<String> end = new HashSet<String>();//结束端
        boolean[] flag = new boolean[10001];//标记
        
        start.add("0000");
        end.add(target);
        
        //标记死亡数字
        for ( int i = 0; i < deadends.length; i++ ) flag[Integer.parseInt(deadends[i])] = true;
        if ( flag[0] ) return -1;//如果以标记
        
        return BFS(start, end, flag, 1);
    }
	
    //双向BFS
    //st是开始端，ed是结束端，flag是标记，cnt是转动次数
	public static int BFS( HashSet<String> st, HashSet<String> ed, boolean[] flag , int cnt) {
		if ( st.size() <= 0 ) return -1;//出现断层
		if ( st.size() > ed.size() ) {//找小的一端开始
			return BFS(ed, st, flag, cnt);
		}
		
		int[] num = {0,1,2,3,4,5,6,7,8,9};//轮盘
		int[] change = {1,-1};//转动数字
		HashSet<String> next = new HashSet<String>();//存储下一波
		
		//遍历
		for ( String string : st ) {
			flag[Integer.parseInt(string)] = true;//标记为访问
			
			char[] arrs = string.toCharArray();	//获取当前数字
			for ( int i = 0; i < string.length(); i++ ) {//遍历字符
				char temp = string.charAt(i);//当前字符
				for ( int j = 0; j < change.length; j++ ) {//转动数字
					int c = num[(temp-'0'+10+change[j])%10];
					arrs[i] = (char)(c+'0');
					String nstr = new String(arrs);
					if ( !flag[Integer.parseInt(nstr)] ) {//如果不是死亡数据且未访问
						if ( ed.contains(nstr) ) return cnt;//如果碰撞
						else next.add(nstr);
					}
				}
				arrs[i] = temp;//复原单词
			}
		}
		
		return BFS(next, ed, flag, cnt+1);
	}
}
```

