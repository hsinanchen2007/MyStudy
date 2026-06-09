```
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        //BFS
        Queue<String> queue = new LinkedList<String>();
        List<String> visit = new ArrayList<String>();
        int pathCount = 0;
        queue.add(beginWord);
        while(!queue.isEmpty()){
            pathCount++;
            int size = queue.size();
            for(int i = 0;i<size;i++){
                String temp = queue.poll();
                if(temp.equals(endWord)){
                    return pathCount;
                }
                for(String word:wordList){
                    if(!visit.contains(word)&&isOneDiff(temp,word)){
                        queue.add(word);
                        visit.add(word);
                    }
                }
            }

        }
        return 0;
    }
    public boolean isOneDiff(String a,String b){
        char[] achar = a.toCharArray();
        char[] bchar = b.toCharArray();
        if(achar.length!=bchar.length) return false;
        int count = 0;
        for(int i =0;i<achar.length;i++){
            if(achar[i]!=bchar[i]){
                count ++;
            }
            if(count>1){
                return false;
            }
        }
        if(count == 1){
            return true;
        }else{
            return false;
        }
    }
}
```
