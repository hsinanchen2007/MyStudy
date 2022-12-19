### 解题思路
1:首先第一步我们得找到根节点 因为我们要从根节点开始便利
2：从根节点进行深度优先搜索 如果每个结点都能遍历到且不存在一个结点被多次遍历就返回true

### 代码

```java
class Solution {
  public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
        boolean[] isVisited=new boolean[n];
        int root=0; //根节点
        //找到根节点
		for (int i = 0; i <n ; i++) {
			int r=0;
             //既没有出现再左子树数组 又没有出现在右子树数组 
			while (r<n && i!=leftChild[r] && i!=rightChild[r] ){
				r++;
			}
			if(r==n) {
				root=i;
				break;
			}
		}
		//进行深度遍历
		boolean flag=dfsTree(root,leftChild,rightChild,isVisited);
        if(flag==false) return false; 
        //flag为true只是不存在用一个结点被遍历多次  还要考虑是否全部被遍历到
		for (int i = 0; i <isVisited.length ; i++) {
			if(!isVisited[i]) return false;
		}
		return true;
	}

	private boolean dfsTree(int i, int[] leftChild, int[] rightChild, boolean[] isVisited) {
		if(isVisited[i]) return false;
		isVisited[i]=true;
	    if(leftChild[i]!=-1){
	        if(!dfsTree(leftChild[i],leftChild,rightChild,isVisited)) return false;
		}
	    if(rightChild[i]!=-1){
	    	if(!dfsTree(rightChild[i],leftChild,rightChild,isVisited)) return false;
		}
	    return true;
	}
}
```