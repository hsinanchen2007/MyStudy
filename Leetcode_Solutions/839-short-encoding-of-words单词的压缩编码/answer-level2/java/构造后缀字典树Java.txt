执行用时 :17 ms, 在所有 Java 提交中击败了97.74%的用户
内存消耗 :45.6 MB, 在所有 Java 提交中击败了6.06%的用户
### 解题思路
后缀字典树，详解见代码注释。
### 代码

```java
class Solution {
    class DicTreeNode {
		int count ;
		DicTreeNode nodes[] ;
		DicTreeNode(){
			nodes = new DicTreeNode[26] ; 
		}
		DicTreeNode getNext(char c) {
			if(nodes[c-'a']==null) {
				nodes[c-'a'] = new DicTreeNode() ;
				count++ ; //这个单词前面还有东西，不能作为叶子节点算进去
			}
			return nodes[c-'a'] ;
		}
	}
	
	public int minimumLengthEncoding(String[] words) {
			HashMap<DicTreeNode,Integer> map = new HashMap<>() ; //key存的每一个单词尾到根的那部分数组（有的在中间所以count!=0，有的是当前最末尾那种词儿，那么count=0），value存的这个单词在words中的index
			DicTreeNode head = new DicTreeNode() ;
			for(int i=0;i<words.length;i++) {
				String word = words[i] ;
				DicTreeNode temp = head ; //需要有一个head来保存这些所有单词的尾巴字母，这样才能记忆搜索
				for(int j=word.length()-1;j>=0;j--) {
					temp = temp.getNext(word.charAt(j)) ;
				}
				map.put(temp,i) ;
			}
			int ans = 0 ;
			for(DicTreeNode node:map.keySet()) {
				if(node.count==0) {
					ans += (words[map.get(node)].length()+1) ;// 只加字典树末尾的，因为末尾的后面没字母了所以count=0，而且只有末尾才贡献了单独的单词，在这个末尾单词路径内的都没贡献。
				}
			}
			return ans ;
	}
}
```