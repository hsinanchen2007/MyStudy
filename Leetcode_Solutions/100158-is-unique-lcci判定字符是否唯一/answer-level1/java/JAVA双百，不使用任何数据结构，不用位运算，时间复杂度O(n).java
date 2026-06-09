    public boolean isUnique(String astr) {
        //用于扩展ASCII码
        int[] index = new int[256];
        //每个字符出现则+1
        for (int i = 0; i < astr.length(); i++) {
            index[astr.charAt(i)] += 1;
        }
        //出现两次就F
        for (int i = 0; i < index.length; i++) {
            if (index[i]>1){
                return false;
            }

        }
        return true;
    }