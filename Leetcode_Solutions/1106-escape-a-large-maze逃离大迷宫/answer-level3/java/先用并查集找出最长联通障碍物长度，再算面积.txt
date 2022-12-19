并查集找出最长联通障碍物长度
算出最长障碍物可以围成的最大面积 (三角形的斜边，点阵不用1/4圆)
分别广搜起点和终点，都能搜到大于最大面积则返回true。

剪枝1：并查集时顺便判断，只有2个或以上障碍物挨着墙边，或者障碍物集合形成环状，才进行下一步操作，		否则直接return true;
剪枝2: 对起点广搜期间，遇到终点立马return true

时间：112ms, 78.31%
内存：50.3Mb,  100.00%

```
import java.util.*;
class Solution {
    int name = 1;
	boolean chose = false;
	int[] sour; 
	int[] targ;
	int s;
	
	// 找出最长联通障碍物长度
    // 算出最长障碍物可以围成的最大面积（1/4 个圆包住迷宫的一个角）
    // 分别广搜起点和终点，都能搜到大于最大面积则返回true。
    public boolean isEscapePossible(int[][] blocked, int[] source, int[] target) {
        s = findMax(blocked);
        if(s == -1) return true;
        sour = source;
        targ = target;
        chose = true;
        Boolean k1 = go(source);
        if(k1==null) return true;
        if(!k1) return false;
        chose = false;
        Boolean k2 = go(target);
        if(k2==null||k2) return true;
        return false;
    }
    
    int[][] to = {{-1,0},{1,0},{0,-1},{0,1}};
    int[][] to2 = {{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{-1,-1},{1,-1}};
    Map<String, Root> cache = new HashMap<String, Root>();
    Set<String> cache2 = new HashSet<String>();
    public int findMax(int[][] blo) {
    	boolean fin = false;
    	int max = 0;
    	int bj = 0;
    	for(int[]b : blo) {
    		String sig = b[0]+","+b[1];
    		if(b[0]==0||b[1]==0) bj++;
    		Map<Integer, Root>roots = new HashMap<>();
    		for(int[]td : to2) {
    			String toSig = (b[0]+td[0])+","+(b[1]+td[1]);
    			Root rt = cache.get(toSig);
	    		if(rt!=null) {
	    			Root rtFa = Root.findFa(rt);
	    			if(roots.containsKey(rtFa.name)) fin = true;
	    			roots.put(rtFa.name, rtFa);
	    		}
    		}
    		Collection<Root> r = roots.values();
    		Root myRoot = new Root(name++, 1);
    		if(r.size()!=0) {
    			for(Root rr:r) {
    				rr.fa = myRoot;
    				myRoot.value += rr.value;
    			}
    		}
    		cache.put(sig, myRoot);
    		if(myRoot.value>max) max = myRoot.value;
    	}
    	if(!fin&&!(bj==2)) return -1;
    	return (int)(Math.pow(max*2/Math.PI,2)*Math.PI);
    }
    
    public Boolean go(int[] source) {
    	Queue<int[]> q = new LinkedList<>();
    	q.offer(source);
    	int count = 0;
    	while(q.size()!=0) {
    		int[]cu = q.poll();
    		if(++count>s) return true;
    		for(int[]td:to) {
    			int[]toGo = {cu[0]+td[0], cu[1]+td[1]};
    			if(toGo[0]<0||toGo[1]<0) continue;
    			if(chose && toGo[0]==targ[0]&&toGo[1]==targ[1]) return null;
    			String sig = toGo[0]+","+toGo[1];
    			if(cache.containsKey(sig)||cache2.contains(sig))
    				continue;
    			cache2.add(sig);
    			q.offer(toGo);
    		}
    	}
    	return false;
    }
    
    
	
}
class Root{
	Integer name;
	int value;
	Root fa;
	Root(Integer name, int value){
		this.name = name;
		this.value = value;
	}
	static Root findFa(Root cu) {
		while(cu.fa!=null) cu=cu.fa;
		return cu;
	}
}

```
