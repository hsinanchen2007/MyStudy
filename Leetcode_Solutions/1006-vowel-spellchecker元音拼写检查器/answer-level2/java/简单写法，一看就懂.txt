```
private String convert(String str) {
        char[] arr = str.toCharArray();
        for(int j = 0; j < arr.length; j++) {
            if (arr[j] == 'a' || arr[j] == 'e' || arr[j] == 'i' 
                || arr[j] == 'o' || arr[j] == 'u') {
                arr[j] = '#';
            }
        }
        return new String(arr);
    }
    
    public String[] spellchecker(String[] wordlist, String[] queries) {
        int len = queries.length;
        
        int len1 = wordlist.length;
        HashMap<String, Integer> map1 = new HashMap();
        HashMap<String, Integer> map2 = new HashMap();
        HashMap<String, Integer> map3 = new HashMap();
        
        for(int i = len1 - 1; i >= 0; i--) {
            map1.put(wordlist[i], i);
            
            String str = wordlist[i].toLowerCase();
            map2.put(str, i);
            
            map3.put(convert(str), i);
        }
        
        String[] res = new String[len];
        for(int i = 0; i < len; i++) {
            String query = queries[i];
            Integer index = map1.get(query);
            if (index != null) {
                res[i] = wordlist[index];
                continue;
            }
            
            String queryL = query.toLowerCase();
            index = map2.get(queryL);
            if (index != null) {
                res[i] = wordlist[index];
                continue;
            }
            
            String str = convert(queryL);
            index = map3.get(str);
            if (index != null) {
                res[i] = wordlist[index];
                continue;
            }
            
            res[i] = "";
        }
        
        return res;
    }
```
