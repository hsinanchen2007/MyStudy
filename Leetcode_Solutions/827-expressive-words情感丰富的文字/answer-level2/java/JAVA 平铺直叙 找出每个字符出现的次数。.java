  public int expressiveWords(String S, String[] words) {
        int count0 = 0 ;
        int count1 = 0 ;
        int count = 0 ;
        int i = 1 ;
        int j = 1 ;
        int k = 0 ;
        for(k=0;k<words.length;k++){
            char first0=S.charAt(0);
            char first1=words[k].charAt(0);
            i=0;j=0;
            int flag = 0 ;
            while(i<S.length() && j<words[k].length()){
                count1=0;
                count0=0;
                while(i<S.length() && S.charAt(i)==first0){
                    count0++;
                    i++;
                }
                while(j<words[k].length() && words[k].charAt(j)==first1){
                    count1++;
                    j++;
                }
                if(first0!=first1){
                    flag = 1 ;
                    break;
                }
                if(count0>count1 && count0==2){
                    flag=1;
                    break;
                }
                if(count1>count0){
                    flag=1;
                    break;
                }
                if(i<S.length()){
                    first0=S.charAt(i);
                }
                if(j<words[k].length()){
                    first1=words[k].charAt(j);
                }
            }
            if(flag!=1 && i==S.length() && j==words[k].length()){
                count++;
            }
        }
        return count;
    }