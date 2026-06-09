```
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList_) {//形参换个名字
        Set<String> wordList = new HashSet<>(wordList_);//把字典换成哈希表，提高查询效率
        if(!wordList.contains(endWord)) return 0;
        Set<String> beginSet = new HashSet<String>();
        Set<String> endSet = new HashSet<String>();
        
        int len = 1;
        HashSet<String> visited = new HashSet<>();
        beginSet.add(beginWord);
        endSet.add(endWord);
        //BFS 
        while(!beginSet.isEmpty() && !endSet.isEmpty()) {
        	//我们优先扩展小的Set
        	if(beginSet.size() > endSet.size()) {
        		Set<String> set = beginSet;
        		beginSet = endSet;
        		endSet = set;
        	}
        	Set<String> tmp = new HashSet<String>();
        	for(String word : beginSet) {
        		char[] cs = word.toCharArray();
        		for(int i = 0;i < cs.length;i++) {//对单词的每一位字符，进行 a--z 的替换
        			for(char c = 'a';c <= 'z';c++) {
        				char old = cs[i];//保存旧字符
        				cs[i] = c;//替换
        				String target = String.valueOf(cs);//得到新单词
        				if(endSet.contains(target)) {//找到了
        					return len + 1;
        				}
        				if(!visited.contains(target) && wordList.contains(target)) {
        					tmp.add(target);
        					visited.add(target);
        				}
        				cs[i] = old;
        			}
        		}
        	}
        	beginSet = tmp;
        	len++;
        }
//若出现一方集合为空，说明不存在可行的转换序列
        return 0;
    }
}
```
