
```
    public int expressiveWord(String S, String[] words) {
        
        //list: h, eee, ll, ooo
        ArrayList<String> list = new ArrayList<>();
        int i = 0, start = 0;
        for (; i < S.length() - 1; i++) {
            if (S.charAt(i) != S.charAt(i + 1)) {
                String s = S.substring(start, i + 1);
                list.add(s);
                start = i + 1;
            }
        }
        //add last string 
        list.add(S.substring(start, i + 1));


        int result = 0;
        for (String word : words) {
            boolean flag = true;
            int j = 0;
            for (i = 0, start = 0; i < word.length() - 1; i++) {

                if (j > list.size()) {
                    flag = false;
                    break;
                }

                if (word.charAt(i) != word.charAt(i + 1)) {
                    String s = word.substring(start, i + 1);
                    if (list.get(j).indexOf(s) == -1) {
                        flag = false;
                        break;
                    }

                    if (list.get(j).length() < 3 && (list.get(j).length() != s.length())) {
                        flag = false;
                        break;
                    }
                    start = i + 1;
                    j++;
                }
            }
            
            
            if (flag) {
                String s = word.substring(start, i + 1);
                if (list.size() - 1 == j && // j equals index of list，
                        list.get(j).indexOf(s) != -1 && //s is substring of list's element
                        (list.get(j).length() >= 3 // 大于3，随便子串的长度是多少
                                || (list.get(j).length() == s.length() //小于，必须长度相等
                        ))) {
                    result++;
                }
            }
        }
        return result;
    }
```
