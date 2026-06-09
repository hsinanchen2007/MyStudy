```
private boolean check(char[] array, int i, int j) {
        while(i < j) {
            if (array[i++] != array[j--]) {
                return false;
            }
        }
        
        return true;
    }
    
    public List<List<Integer>> palindromePairs(String[] words) {
        int len = words.length;
        Map<String, Integer> map = new HashMap();
        for(int i = 0; i < len; i++) {
            map.put(words[i], i);
        }
        
        List<List<Integer>> res = new ArrayList();
        for(int i = 0; i < len; i++) {
            String word = words[i];
            
            String re = new StringBuffer(word).reverse().toString();
            Integer index = map.get(re);
            if (index != null && index.intValue() != i) {
                List<Integer> pair = new ArrayList(2);
                pair.add(index);
                pair.add(i);
                res.add(pair);
            }
            
            char[] arr = word.toCharArray();
            for(int j = 0; j < arr.length; j++) {
                if (check(arr, 0, j)) {
                    String sub = new StringBuffer(word.substring(j+1)).reverse().toString();
                    index = map.get(sub);
                    if (index != null && index.intValue() != i) {                        
                        List<Integer> pair = new ArrayList(2);
                        pair.add(index);
                        pair.add(i);
                        res.add(pair);
                    }
                    
                }
            }
            
            for(int j = arr.length - 1; j >= 0; j--) {
                if (check(arr, j, arr.length - 1)) {
                    String sub = new StringBuffer(word.substring(0, j)).reverse().toString();
                    index = map.get(sub);
                    if (index != null && index.intValue() != i) {
                        List<Integer> pair = new ArrayList(2);
                        pair.add(i);
                        pair.add(index);
                        res.add(pair);
                    }
                }
            }
        }
        return res;
    }
```
