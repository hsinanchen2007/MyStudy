```
public boolean isScramble(String s1, String s2) {
        if(s1.length() != s2.length()){
            return false;
        }
        if(s1.equals(s2)){
            return true;
        }
        int [] hash1 = new int[26];
        int[] hash2 = new int[26];
        for(char c : s1.toCharArray()){
            hash1[c - 'a']++;
        }
        for(char c : s2.toCharArray()){
            hash2[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(hash1[i] != hash2[i]){
                return false;
            }
        }
        return compare(s1, s2, 0, s1.length() - 1, 0, s2.length() - 1);
    }
    public boolean compare(String s1, String s2, int l1, int r1, int l2, int r2){
        if(s1.substring(l1, r1).equals(s2.substring(l2, r2))){
            return true;
        }
        int need = 0;
        int[] hash1 = new int[26];
        int[] hash2 = new int[26];
        for(int i = l1, j=l2; i < r1; i++, j++){
            int ci = s1.charAt(i);
            int cj = s2.charAt(j);
            boolean flag = false;
            if(ci != cj){
                if(hash2[ci - 'a'] > 0){
                    hash2[ci - 'a']--;
                    need--;
                }else{
                    hash1[ci - 'a']++;
                    need++;
                }
                if(hash1[cj - 'a'] > 0){
                    hash1[cj - 'a']--;
                    need--;
                }else{
                    hash2[cj - 'a']++;
                    need++;
                }
            }
            if(need == 0){  
                flag = compare(s1, s2, l1, i, l2, j) && compare(s1, s2, i + 1, r1, j + 1, r2);
            }
            if(flag){
                return true;
            }
        }
        need = 0;
        hash1 = new int[26];
        hash2 = new int[26];
        for(int i = l1, j=r2; i < r1; i++, j--){
            int ci = s1.charAt(i);
            int cj = s2.charAt(j);
            boolean flag = false;
            if(ci != cj){
                if(hash2[ci - 'a'] > 0){
                    hash2[ci - 'a']--;
                    need--;
                }else{
                    hash1[ci - 'a']++;
                    need++;
                }
                if(hash1[cj - 'a'] > 0){
                    hash1[cj - 'a']--;
                    need--;
                }else{
                    hash2[cj - 'a']++;
                    need++;
                }
            }
            if(need == 0){
                flag = compare(s1, s2, l1, i, j, r2) && compare(s1, s2, i + 1, r1, l2, j - 1);
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
```
每次递归必须判断所用字母个数是否相同，相同时才会递归比较。有空再补充。