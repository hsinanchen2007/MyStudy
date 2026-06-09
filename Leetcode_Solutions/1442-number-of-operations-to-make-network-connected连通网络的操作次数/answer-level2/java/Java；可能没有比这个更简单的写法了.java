### 解题思路

参考了 wenhaooo 的题解（就是这道题目题解里的一个人的题解），做了部分优化。增加加了一些解释

### 代码

```java
//可能写的有些混乱，不太清楚的可以评论。
//把这个关系，记作掌门和弟子的关系，掌门即为众多弟子的领袖，是他们这个小团体的代表。
//或者就是在几个帮派的弟子里找这些帮派的大师兄的过程，这几个大师兄再拜在一个师傅的门下。
class Solution {
	int []a;      // 索引为弟子编号，值为掌门。
	int find(int x)        //找掌门
	{
		if(a[x]!=x)        //如果这人不是掌门
		{
			a[x]=find(a[x]);  //找辈分比他高的
		return a[x];       //是掌门就不动
	}
	void f(int x,int y)    //这两人是一个门派的
	{
		int f1=find(x),f2=find(y);  
		if(f1!=f2)           //如果这两人掌门不一样，一个是师叔，一个是掌门，掌门只有一个，两人平辈
		a[f2]=a[f1];         //就按先出现的是掌门
	}
    public int makeConnected(int n, int[][] connections) {
    	if(connections.length<n-1) return -1;//n个节点联通起来需要n-1条边，没有这么多边不可能联通
        a=new int[n];//初始化
        for(int i=0;i<n;i++)
        a[i]=i;      //假设每个弟子都是掌门人
        for(int i=0;i<connections.length;i++)
        	f(connections[i][0],connections[i][1]); //一些弟子合并
        HashSet<Integer> hs=new HashSet();
        int res=0;
        for(int i=0;i<n;i++)
        {
            a[i]=find(a[i]);    //过程中，可能有些值是师叔，不是掌门，通过这操作变成掌门
        }
        for(int i:a)
        {
            hs.add(i);         //看有几个掌门
        }
            //System.out.println();
        //n个联通块合并需要n-1条边
        return hs.size()-1; 
    }
}
```