### 解题思路
DFS，只不过与当前节点相邻是与之只差一个字母的string
1.先实现一个函数，返回与当前String 只差一个字母的字符串列表。
2.遍历返回的列表中的string：
    如果与endword相等，则返回结果。
    如果与endword不等，继续dfs
    如果已经遍历完当前列表还没找到endword, 说明这个路径不对，删除当前string, 回溯到上一层

### 代码

```java
class Solution {
    List<String> wordList;
    boolean[] marked;
    List<String> output;
    String endWord;
    List<String> result;
    public List<String> findLadders(String beginWord, String endWord, List<String> wordList) {
        this.wordList=wordList;
        output=new ArrayList();
        marked=new boolean[wordList.size()];
        result=new ArrayList();
        this.endWord=endWord;
        dfs(beginWord);
        return result;
    }

    public void dfs(String s){
        output.add(s);
        Queue<String> queue=oneCharDiff(s);
        for(String str:queue){
            if(str.equals(endWord)) {
               output.add(str);
            	result=new ArrayList(output);
            	return; 
            }
            dfs(str);
            output.remove(output.size()-1);
        }
        
    }
    public Queue<String> oneCharDiff(String s){
        Queue<String> queue=new LinkedList();
        for(int j=0;j<wordList.size();j++){
            String str=wordList.get(j);
            int diffNum=0;
            if(str.length()!=s.length() || marked[j]) continue;
            for(int i=0;i<str.length();i++){
                if(diffNum>=2) break;
                if(str.charAt(i)!=s.charAt(i)) diffNum++;
            }
            if(diffNum==1) {
                queue.add(str);
                marked[j]=true;
            }
        }
        return queue;
    }
}
```