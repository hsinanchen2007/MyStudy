class Solution {
    public List<String> findLadders(String beginWord, String endWord, List<String> wordList) {
        Map<String,List<String>> map = new HashMap<>();
        wordList.add(beginWord);
        int len = wordList.size();
        for(int i=0;i<len;i++){
            List<String> list = new ArrayList<>();
            for(int j=0;j<len;j++){
                if(diffOne(wordList.get(i),wordList.get(j))){
                    list.add(wordList.get(j));
                }
            }
            map.put(wordList.get(i),list);
        }
        Set<String> visited = new HashSet<>();
        Queue<Rec> queue = new LinkedList<>();
        queue.add(new Rec(beginWord,new ArrayList(Arrays.asList(new String[]{beginWord}))));
        while(!queue.isEmpty()){
            Rec rec = queue.remove();
            List<String> list = map.get(rec.word);
            if(list.contains(endWord)){
                rec.wayWords.add(endWord);
                return rec.wayWords;
            }else{
                for(String str : list){
                    if(!visited.contains(str)){
                        List<String> tmp = new ArrayList<>(rec.wayWords);
                        tmp.add(str);
                        Rec rc = new Rec(str,tmp);
                        queue.add(rc);
                        visited.add(str);
                    }
                }
            }
        }
        return new ArrayList<>();
    }

    private boolean diffOne(String one,String another) {
        int notSameSum = 0;
        for(int i=0;i<one.length();i++){
            if(one.charAt(i) != another.charAt(i)){
                notSameSum++;
            }
        }
        return notSameSum == 1;
    }

    class Rec{
        String word;
        List<String> wayWords;

        public Rec(String word, List<String> wayWords) {
            this.word = word;
            this.wayWords = wayWords;
        }
    }
    
}