char[] chars = astr.toCharArray();
        for (int i = 0; i < chars.length; i++) {
            for (int j = 0; j < chars.length; j++) {
                if(i == j ){
                    continue;
                }
                if(chars[i] == chars[j]){
                    return false;
                }
            }
        }
        return true;