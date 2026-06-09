### 解题思路
**Set在BFS和DFS中可以巧妙运用**

### 代码

```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> _wordList) {
     HashSet<String> wordList=new HashSet<>(_wordList);
		if(!wordList.contains(endWord))return 0;
		Queue<String> queue=new LinkedList<>();
		queue.add(beginWord);
		int ans=1;
		while(!queue.isEmpty()) {
			int curSize = queue.size();
			ans++;
			while (curSize > 0) {
				String cur = queue.poll();
				char[] chs = cur.toCharArray();
				for (int i = 0; i < chs.length; ++i) {
					char before = chs[i];
					for (char ch = 'a'; ch <= 'z'; ++ch) {
						if(ch==before)continue;
						chs[i] = ch;
						String _cur = new String(chs);
						if (wordList.contains(_cur)) {
							if (_cur.equals(endWord))
								return ans;
							queue.add(_cur);
							wordList.remove(_cur);
						}
					}
					chs[i] = before;
				}
				curSize--;
			}
		}
		return 0;
    }
}
```