`纪念第一次完整写出字典树  好开心`
```
class Solution {
    private class Node{
        String val;
        TreeMap<Character, Node> next;
        public Node(){
            next = new TreeMap<>();
        }
    }
    
    private Node root = new Node();

    public void insert(String word){
        Node cur = root;
        for(int i = 0; i < word.length(); i++){
            char c = word.charAt(i);
            if(!cur.next.containsKey(c))
                cur.next.put(c, new Node());          
            cur = cur.next.get(c);
        }
        cur.val = word;
    }
    
    public String checkPrefix(String word){
        Node cur = root;
        for(int i = 0; i < word.length(); i++){
            char c = word.charAt(i);
            if(cur.val != null)
                return cur.val;      
            if(cur.next.containsKey(c))
                cur = cur.next.get(c);
            else
                return word;
            }
        
        return word;
    }
  
    public String replaceWords(List<String> dict, String sentence) {
        for(int i = 0; i < dict.size(); i++){
            insert(dict.get(i));
        }

        StringBuilder res = new StringBuilder();
        int i = 0;
        int j = 0;
        int len = sentence.length(); 
        while(j < len){      
            while(j < len && sentence.charAt(j) != ' ')
                j++;
            
            if(j < len - 1){
                res.append(checkPrefix(sentence.substring(i, j)));
                res.append(" ");
            }else
                res.append(checkPrefix(sentence.substring(i, len)));
            j = j + 1;
            i = j;
           
        }
        return res.toString();
    }
}


```
