### 解题思路

单向BFS，没有用双向BFS。本解法的特点在于，用索引去代替字符串去做bfs和去重。

执行用时 : 60 ms , 在所有 Java 提交中击败了 74.51% 的用户

### 代码

```java
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        
        List<List<String>> result = new ArrayList<List<String>>();
        
        //init
        HashMap<String, List<Integer>> map = new HashMap<>();
        boolean preCheckExist = false;
        
        for(int i=0; i<wordList.size() ;i++)
        {
            if(endWord.equals(wordList.get(i)))
            {
                preCheckExist = true;
            }
            
            for(String prefixKey: generateKey(wordList.get(i)))
            {
                if(!map.containsKey(prefixKey))
                {
                    map.put(prefixKey, new ArrayList<Integer>());
                }
                
                map.get(prefixKey).add(i);
            }
        }
        
        if(!preCheckExist)
        {
            return result;
        }
        
        boolean[] used = new boolean[wordList.size()];
        //cur, parent 
        HashMap<Integer, List<Integer>> parentMap = new HashMap<Integer, List<Integer>>();
        
        //bfs
        Queue<Integer> q = new LinkedList<Integer>();
        q.add(-1);
        int level = 0;
        
        while(!q.isEmpty())
        {
            int size = q.size();
            HashSet<Integer> nextLevelIndices = new HashSet<>();
            
            for(int i=0;i<size;i++)
            {
                int cur = q.remove();
                
                List<String> candidateKeys;
                if(cur==-1)
                {
                    candidateKeys = generateKey(beginWord); 
                }
                else
                {
                    candidateKeys = generateKey(wordList.get(cur)); 
                }
                
                for(String prefixKey: candidateKeys) 
                {
                    List<Integer> nextIndices = map.get(prefixKey);
                    
                    if(nextIndices==null)
                    {
                        continue;
                    }
                    
                    
                    for(int nextIndex: nextIndices)
                    {
                        if(used[nextIndex])
                        {
                           continue; 
                        }
                        
                        nextLevelIndices.add(nextIndex);
                        
                        if(!parentMap.containsKey(nextIndex))
                        {
                            parentMap.put(nextIndex, new ArrayList<Integer>());
                        }
                        
                        parentMap.get(nextIndex).add(cur);
                    }
                }
            }
            
            //this level conclusion
            for(int nextIndex: nextLevelIndices)
            {
                q.add(nextIndex);
                used[nextIndex] = true;
                
                if(wordList.get(nextIndex).equals(endWord))
                {
                    result = getPathToRoot(parentMap, nextIndex, wordList, beginWord);
                    return result;
                } 
            }
                
            
            level++;
        }
        
        return result;
        
    }
    
    public List<List<String>> getPathToRoot(HashMap<Integer, List<Integer>> parentMap, int endIndex, 
                                            List<String> wordList, String beginWord)
    {
        List<List<String>> result = new ArrayList<List<String>>();
        
        
        
        helper(parentMap, endIndex, wordList, beginWord,
               endIndex, new LinkedList<String>(),
               result);
        
        return result;
        
        
    }
    
    
    public void helper(final HashMap<Integer, List<Integer>> parentMap, final int endIndex, final List<String> wordList, final String beginWord,
                       int curIndex, LinkedList<String> curResult,
                       List<List<String>> result)
    {
        if(curIndex==-1)
        {
            curResult.addFirst(beginWord);
            result.add(new LinkedList<String>(curResult));
            curResult.removeFirst();            
        }
        else
        {
            curResult.addFirst(wordList.get(curIndex));

            List<Integer> parentList = parentMap.get(curIndex);

            for(int parent: parentList)
            {
                helper(parentMap, endIndex, wordList, beginWord,
                       parent, curResult,
                       result);            
            }

            curResult.removeFirst();               
        }
        

        
    }
    

    public List<String> generateKey(String word)
    {
        List<String> result = new ArrayList<>();
        for(int i=0;i<word.length();i++)
        {
            String cur = word.substring(0,i) + "*" + word.substring(i+1, word.length());
            result.add(cur);
        }
        
        return result;
    }
    
    
}
```