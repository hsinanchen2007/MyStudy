思路：遍历节点，算出每个节点的出度和入度。如果一个节点是法官，那么该节点的入度为 N-1,出度为 0，如果没有这种节点，返回 -1。
C++ 版代码：
```
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int inDegree[1001], outDegree[1001];                    // 定义两个数组分别存储每一个节点的入度和出度 
    	int peopleMark;                                         // 记录人的编号 
    	memset(inDegree, 0, sizeof(inDegree));                  // 把两个数组初始化为 0  
		memset(outDegree, 0, sizeof(outDegree)); 
		for(int i = 0; i < trust.size(); i++){		 			
				peopleMark = trust[i][0];
				outDegree[peopleMark]++;                       // 人的出度加1 
				peopleMark = trust[i][1];
				inDegree[peopleMark]++;                        // 人的入度加 1					
			} 
		for(int i = 1; i <= N; i++){
			if(inDegree[i] == (N - 1) && outDegree[i] == 0)
				return i; 
		}   	           
        return -1;
    }
};
```


Java 版代码：

```
class Solution {
    public int findJudge(int N, int[][] trust) {
        int inDegree[]  = new int[1001];       // 定义两个数组分别存储每一个节点的入度和出度
		int	outDegree[] = new int[1001];                     
    	int peopleMark;                            // 记录人的编号 
    	for(int i = 0; i < trust.length; i++) {
    		peopleMark = trust[i][0];
			outDegree[peopleMark]++;               // 人的出度加1 
			
			peopleMark = trust[i][1];
			inDegree[peopleMark]++;                // 人的入度加 1
    	}
    	for(int i = 1; i <= N; i++){               // 判断一个人的出度和入度来判断是否是法官 
			if(inDegree[i] == (N - 1) && outDegree[i] == 0)
				return i; 
		}   	           
		return -1;  
    }
}
```
