```
1、判断当前字符串是否是其他字符串的前缀
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set = new HashSet<>();
        for(int i = 0;i<words.length; i++) {
            set.add(words[i]);
        }
        Map<String, Integer> map = set.stream().collect(Collectors.toMap(e -> e, e -> e.length()));
        List<Map.Entry<String, Integer>>  list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o2.getValue()-o1.getValue();
            }
        });
        
        StringBuilder sb = new StringBuilder();
        sb.append(list.get(0).getKey()).append("#");
        for(int i = 1; i < set.size(); i++) {
            String curWord = list.get(i).getKey();
            boolean contains = false;
            for(int j = 0; j<i; j++) {
                if(list.get(j).getKey().endsWith(curWord)) {
                    contains = true;
                    break;
                }
            }
            if(!contains) {
                sb.append(curWord).append("#"); 
            }
        }
        return sb.toString().length();
    }
}

2、字典树（待进一步优化）
class Solution {
    public int minimumLengthEncoding(String[] words) {
        Set<String> set = new HashSet<>();
        for(int i = 0;i<words.length; i++) {
            set.add(words[i]);
        }
        Map<String, Integer> map = set.stream().collect(Collectors.toMap(e -> e, e -> e.length()));
        List<Map.Entry<String, Integer>>  list = new ArrayList<>(map.entrySet());
        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
            @Override
            public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                return o2.getValue()-o1.getValue();
            }
        });

        TrieNode root = new TrieNode(' ');
        StringBuilder sb = new StringBuilder();
        char wordChars[] = null;
        for(int i = 0; i < set.size(); i++) {
            String curWord = list.get(i).getKey();
            wordChars = list.get(i).getKey().toCharArray();
            if(!contains(root, wordChars, wordChars.length-1)) {
                sb.append(curWord).append("#"); 
            }
        }
        return sb.toString().length();
    }

    private boolean contains(TrieNode root, char[] wordChars, int index)  {
        if(index<0) {
            return true;
        }
        List<TrieNode> children = root.children;
        int flag = 0;
        for(TrieNode child : children) {
            if(child.val == wordChars[index]) {
                return contains(child, wordChars, index-1);
            }
        }
        root.children.add(getSonNode(wordChars, index));
        return false;
    }

    private TrieNode getSonNode(char[] wordChars, int index)  {
        if(index<0) {
            return null;
        }
        TrieNode root = new TrieNode(wordChars[index]);
        TrieNode son = getSonNode(wordChars, index-1);
        if(son != null) {
            root.children.add(son);
        }
        return root;
    }
    class TrieNode {
        char val;
        List<TrieNode> children = new ArrayList<>();

        public TrieNode() {}
        public TrieNode(char val) {
            this.val = val;
        }
    }
}
```
