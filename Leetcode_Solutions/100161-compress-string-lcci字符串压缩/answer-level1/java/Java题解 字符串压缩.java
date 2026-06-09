public String compressString(String S) {
        if (S.length()<3)
            return S;
        char c = S.charAt(0);
        int count = 1;
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 1;i<=S.length();i++){
            if (i<S.length()&&S.charAt(i) == c){
                count++;
            }else {
                stringBuilder.append(c);
                stringBuilder.append(count);
                if (i<S.length()){
                    c = S.charAt(i);
                    count = 1;
                }
            }
        }
        return (stringBuilder.toString().length()>S.length())?S:stringBuilder.toString();
    }