```
class Solution {
    private int find(int p,int[]parent) {
	while(p!=parent[p]) {
		p=parent[p];
	}
	return p;
}//寻找p元素的根节点
private void union(int p,int q,int res[],int[] parent) {
	    int pRoot=find(p,parent);//寻找p元素的根节点
	    int qRoot=find(q,parent);//寻找q元素的根节点
	    if(pRoot==qRoot) {
	    	res[0]=p+1;
	    	res[1]=q+1;
	    }//如果两个元素已经在一个集合中，那就说明它们是一对附加的边，将它们放到res中
	    parent[pRoot]=qRoot;//如果两个元素不在一个集合中，那就合并
}//合并两个元素的函数
public int[] findRedundantConnection(int[][] edges) {
       /*
        * 对于这道题我的思路是，每次遇到edges中的一组值时就对这两个点进行合并
        * 合并之前需要判断两个元素是否已经连通了，如果不是，就使其连通，如果是
        * 就将这一组值赋值给一个二元数组res，然后继续寻找 
        */
	//有题目有N个顶点，故edges的大小就是顶点的个数
	int size=edges.length;//设置并查集的大小
	int[]parent=new int[size];
	//初始化每个顶点都属于自己的集合
	for(int i=0;i<parent.length;i++) {
		parent[i]=i;
	}
	//用于存储最后的结果
	int[]res=new int[2];
	for(int i=0;i<edges.length;i++) {
		union(edges[i][0]-1, edges[i][1]-1, res, parent);
	}
	return res;
}
}
```
