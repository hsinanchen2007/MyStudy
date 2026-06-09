
    public String customSortString(String S, String T) {
        StringBuilder ret0 = new StringBuilder();
        StringBuilder ret1 = new StringBuilder();
        int [] count = new int [26] ;
        int i = 0 ;
        for( i = 0 ;i < T.length() ;i++){
            count[T.charAt(i)-'a']++;
        }
        for(i=0;i<T.length();i++){
            if(!S.contains(T.substring(i,i+1))){
                ret1.append(T.charAt(i));
            }
        }
        for(i=0;i<S.length();i++){
         for(int j = 0 ;j< count[S.charAt(i)-'a'] ;j++ ){
                    ret0.append(S.charAt(i));
                }

        }
        ret0.append(ret1.toString());
        return ret0.toString();
    }