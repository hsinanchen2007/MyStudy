```java
class Solution {
    public String alienOrder(String[] words) {
        Map<Character, Set<Character>> graph = new HashMap<>();
        int[] indegree = new int[26];
        Arrays.fill(indegree, -1);
        int count = 0;
        for(String s : words){
            for(char c : s.toCharArray()){
                if(indegree[c-'a']==-1){
                    indegree[c-'a'] = 0;
                    graph.put(c, new HashSet<>());
                    count++;
                }
            }
        }
        for(int i=0;i<words.length-1;i++){
            String cur = words[i];
            String next = words[i+1];
            for(int j=0;j<cur.length()&&j<next.length();j++){
                char a = cur.charAt(j);
                char b = next.charAt(j);
                if(j!=0 && j == next.length()-1 && cur.length() > next.length())   
                    return "";
                if(a != b){
                    if(!graph.get(a).contains(b)){
                        indegree[b-'a']++;
                        graph.get(a).add(b);
                    }
                    break;
                }
            }
        }
        Queue<Character> queue = new LinkedList<>();
        for(int i=0;i<26;i++){
            if(indegree[i] == 0)
                queue.offer((char)(i+'a'));
        }
        StringBuilder sb = new StringBuilder();
        while(!queue.isEmpty()){
            char cur = queue.poll();
            sb.append(cur);
            for(char c : graph.get(cur)){
                indegree[c-'a']--;
                if(indegree[c-'a']==0)
                    queue.offer(c);
            }
        }
        return count == sb.length() ? sb.toString() : "";
    }
}
```