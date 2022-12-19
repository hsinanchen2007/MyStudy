### 解题思路
特别挫的解法，BFS击败了5%的用户，难受

### 代码

```java
class Solution {
    private int Min;
    private String tagStr;
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        boolean ShouldTest = false;
        this.tagStr=endWord;
        Min=0;
        HashMap<String, Boolean> visited = new HashMap<>();
        LinkedList<String> left = new LinkedList<>();
        _Work(beginWord, left, wordList, visited);
        if(this.Min==0)
            return 0;
        else
            return Min+1;
    }
    private void _Work(String beginWord, LinkedList<String> left, List<String> wordList, HashMap<String, Boolean> visited) {
        LinkedList<String>WorkQueue=new LinkedList<>();
        int index=1,level=1;
        WorkQueue.add(beginWord);
        visited.put(beginWord,true);
        while(!WorkQueue.isEmpty()&&this.Min==0){
            beginWord=WorkQueue.poll();
            _GetChild(beginWord,WorkQueue,wordList,visited);
            index--;
            System.out.println(beginWord);
            for(int j=0;j<WorkQueue.size();j++){
                if(WorkQueue.get(j).equals(this.tagStr)){
                    this.Min=level;
                }
            }
            if(index==0){
                index=WorkQueue.size();
                level++;
            }
        }
    }
    private void _GetChild(String tagWord, Queue<String> tag, List<String> wordList,HashMap<String,Boolean>visted) {
        int index=0;
        for(int i=0;i<wordList.size();i++){
            if(tagWord.length()!=wordList.get(i).length()||visted.containsKey(wordList.get(i)))
                continue;
            for(int k=0;k<tagWord.length();k++){
                if(tagWord.charAt(k)!=wordList.get(i).charAt(k))
                    index++;
            }
            if(index==1){
                tag.add(wordList.get(i));
                visted.put(wordList.get(i),true);
            }
            index=0;
        }
    }
}
```