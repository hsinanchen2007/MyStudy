本文参考官方题解:https://leetcode-cn.com/problems/possible-bipartition/solution/
同时将自己的疑惑写出来,供大家参考
# 我的憨批解法（误）
```
class Solution {
	public boolean possibleBipartition(int N, int[][] dislikes) {
		Map<Integer,Integer> map=new HashMap<Integer, Integer>();
		for(int[]cp:dislikes) {
			// 都不在
			if(!map.containsKey(cp[0])&&!map.containsKey(cp[1])) {
				map.put(cp[0],1);
				map.put(cp[1],-1);
			// 都在
			}else if(map.containsKey(cp[0])&&map.containsKey(cp[1])) {
				if(map.get(cp[0])==map.get(cp[1])) return false;
			}else {// 一个在一个不在
				if(map.containsKey(cp[0])) map.put(cp[1],map.get(cp[0])*-1);
				else  map.put(cp[0],map.get(cp[1])*-1);
			}
		}
		return true;
	}
}
```
想法就是给节点上色,上1色或上0色。
- 节点都上色了，就看看是否上的正确。
- 节点一个上色，一个没上色，就把那个没上色的上相反的颜色
- 两个节点都没上色：分别上不同的颜色
我的错误就是在两个节点都没有上色时，其实有两种上色方法的
```
map.put(cp[0],1);
map.put(cp[1],-1);
或
map.put(cp[1],1);
map.put(cp[0],-1);
```
所以很正常的在`{{4,7},{4,8},{2,8},{8,9},{1,6},{5,8},{1,2},{6,7},{3,10},{8,10},{1,5},{7,10},{1,10},{3,5},{3,6},{1,4},{3,9},{2,3},{1,9},{7,9},{2,7},{6,8},{5,7},{3,4}};`这个例子下错了
# 官方解法
```
class Solution {
	ArrayList<Integer>[] graph;// 使用邻接表存储图
	Map<Integer,Integer> color;//记录上色结果
	public boolean possibleBipartition(int N, int[][] dislikes) {
		graph=new ArrayList[N+1];// 0位其实不用,使用的使1~N位
		//ArrayList实例化
		for (int i = 0; i !=N+1; i++) {
			graph[i]=new ArrayList<Integer>();
		}
		//图初始化
		for(int[] cp:dislikes) {
			graph[cp[0]].add(cp[1]);
			graph[cp[1]].add(cp[0]);	
		}
		color=new HashMap();
		for(int node=1;node!=N+1;node++) {// 对该组N人遍历
			if(!color.containsKey(node)) {// 还未上色
				boolean OK=dfs(node,0);//从node开始深度遍历
				if(!OK) return false; 
			}else continue;//已经上色
		}
		return true;
	}
	private boolean dfs(int node, int c) {
		//从possibleBipartition调用时node是未上色的
		if(color.containsKey(node)) {// 若已经上色则看是否上色正确
			boolean OK=(color.get(node)==c);
			return OK;
		}
		color.put(node,c);// 上色
		// 深度遍历
		for(int noFriend:graph[node]) {
			boolean OK=dfs(noFriend,c^1);
			if(!OK) return false;
		}
		return true;
	}
}
```
## 问
1. 为什么官方解法没有要分两类上色呢？
我的想法是遍历dislikes，如果依赖都满足就万事大吉
官方的想法是深度优先遍历，是一个节点一个节点的加入color这个map的
2. 为什么上色时可以直接上色为0？
观察发现那些上色失败的例子，都能组成一个环，深度遍历时就是一个一个环的遍历过去。
对于任意一个环，没上色的第一个元素可以直接上色为0。
已经上色的元素，就自动略过不用管

