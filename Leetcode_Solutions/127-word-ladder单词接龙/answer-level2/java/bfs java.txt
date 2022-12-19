### 解题思路
bfs

### 代码

```java
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {//BFS单源最短
        int ans=0;
        boolean[] visited=new boolean[wordList.size()];//标记已访问过的元素
        Queue<String> q=new LinkedList<String>();//BFS队列
        q.add(beginWord);//将开始单词加入队列，每次循环将可改变一个字母的单词加入队列
        int idx = wordList.indexOf(beginWord);
        if (idx != -1) {
            visited[idx] = true;
        }
        while(q.size()>0)
        {
            int size=q.size();
             ans++;
            while(size-- >0){ 
                String s=q.poll();
           
            for(int i=0;i<wordList.size();i++){
                if(visited[i])
                continue;
                if(!canconvert(s,wordList.get(i)))
                continue;
                if(wordList.get(i).equals(endWord))
                {
                    return ans+1;
                }
                 
                q.add(wordList.get(i));
                visited[i]=true;
                
            }
            }
        }
        return 0;
    }
    public boolean canconvert(String s,String t)
    {
        int count=0;
        for(int i=0;i<s.length();i++)
         {
             if(s.charAt(i)!=t.charAt(i))
              count++;
         }
        return  count<=1;
   }
}
```