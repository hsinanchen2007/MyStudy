# 工程类的题目
 **关键词：Comparator, HashMap and HashSet.**  
    代码比较长，只能一步一步做。当然，你按照提示做也是一样的。
    
## 思路
1. 注意到timestamp不一定是排好序的，先用comparator把Log排好序。
    得到一个Log类的List.
2. Find for every user separately the websites he visited.  
    先遍历一遍logs，把同一个用户按时间顺序访问序列存在哈希表(map1)中。
3. 遍历map1中的用户，对于每个用户的访问序列，生成所有可能的3-sequence visit pattern(此处用3个嵌套for,看着很烦), 并存在哈希表中(map2).
    特别注意的是，这里同一个用户的同一个visit pattern只算一次,所以还要用HashSet来检验。
4. 在更新map2的过程中，同时也更新当前的most frequent visit pattern and the corresponding times.
    这个更新过程，同样要注意If there is more than one solution, return the lexicographically smallest such 3-sequence.




```
class Solution {
    /**
        inner class
    */
    class Log {
        String username;
        int timestamp;
        String website;
        
        public Log(String _username, int _timestamp, String _website) {
            username = _username;
            timestamp = _timestamp;
            website = _website;
        } 
    }
    
    /**
        inner class
        Comparator for Log
    */
    class LogComparator implements Comparator<Log> {        
        @Override
        public int compare(Log log1, Log log2) {
            if( log1.timestamp < log2.timestamp ) {
                return -1;
            }
            else if( log1.timestamp > log2.timestamp ) {
                return 1;
            }
            return 0;
        }        
    }
    
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        
        // Create log
        int len = timestamp.length;
        List<Log> logs = new ArrayList<Log>();
        for( int i = 0; i < len; i++ ) {
            logs.add(new Log(username[i], timestamp[i], website[i]));
        }
        
        // Use comparator to sort the log
        Collections.sort(logs, new LogComparator());
        
        // printLogs(logs);
        
        // HashMap<Username, List<String>> map1
        HashMap<String, List<String>> userVisitMap = new HashMap<String, List<String>>();
        
        // HashMap<3-Sequence, Integer> map2
        HashMap<List<String>, Integer> patternTimesMap = new HashMap<List<String>, Integer>();
        
        // memory: O(N)
        
        // iterate timestamp and build map1
        for( int i = 0; i < logs.size(); i++ ) {
            List<String> visitPattern = userVisitMap.getOrDefault(logs.get(i).username, new ArrayList<String>());
            visitPattern.add(logs.get(i).website);
            userVisitMap.put(logs.get(i).username, visitPattern);
        }
        
        List<String> mostVisitPattern = new ArrayList<String>();
        int maxFrequency = Integer.MIN_VALUE;
        // iterate userVisitMap and generate all 3-sequence pattern
        // N
        for( String user : userVisitMap.keySet() ) {
            List<String> visitPattern = userVisitMap.get(user);
            // get all 3-sequence pattern of a user
            // < N
            // C(n, 3) = n(n-1)(n-2)
            int size = visitPattern.size();
            // Make sure a certain for one user can only count for once
            HashSet<List<String>> set = new HashSet<List<String>>();
            for( int i = 0; i <= size - 3; i++ ) {
                for( int j = i + 1; j <= size - 2; j++ ) {
                    for( int k = j + 1; k <= size - 1; k++ ) {
                        List<String> threeSequence = new ArrayList<String>();
                        threeSequence.add(visitPattern.get(i));
                        threeSequence.add(visitPattern.get(j));
                        threeSequence.add(visitPattern.get(k));
                        if( set.contains(threeSequence) ) {
                            continue;
                        }
                        set.add(threeSequence);
                        int times = patternTimesMap.getOrDefault(threeSequence, 0);
                        times++;
                        patternTimesMap.put(threeSequence, times);
                        if( times > maxFrequency ) {
                            maxFrequency = times;
                            mostVisitPattern = new ArrayList<String>(threeSequence);
                        }
                        else if( times == maxFrequency ) {
                            // If there is more than one solution, 
                            // return the lexicographically smallest such 3-sequence.
                            mostVisitPattern = new ArrayList<String>(getAlphabetSequence(mostVisitPattern, threeSequence));
                        }
                    }
                }
            }      
            
        }
        return mostVisitPattern;      
    }
        
    /**
        return the lexicographically smallest such 3-sequence.
    */
    private List<String> getAlphabetSequence(List<String> mostVisitPattern, List<String> threeSequence) {        
        for( int i = 0; i < 3; i++ ) {            
            // Compare every website
            int index = 0;
            String word1 = mostVisitPattern.get(i);
            String word2 = threeSequence.get(i);
            while( index < word1.length() && index < word2.length() ) {
                if( word1.charAt(index) < word2.charAt(index) ) {
                    return mostVisitPattern;
                }
                else if( word1.charAt(index) > word2.charAt(index) ) {
                    return threeSequence;
                }
                
                // word1.charAt(index) == word2.charAt(index)
                index++;         
            }
            if( index == word1.length() && index < word2.length() ) {
                return mostVisitPattern;
            }
            if( index == word2.length() && index < word1.length() ) {
                return threeSequence;
            }
        }       
        return mostVisitPattern;      
    }
    
    /**
        print all logs
    */
    private void printLogs( List<Log> logs ) {
        for( int i = 0; i < logs.size(); i++ ) {
            Log log = logs.get(i);
            System.out.println(log.username +" " + log.timestamp + " " + log.website);
        }
    }
   
}
```
