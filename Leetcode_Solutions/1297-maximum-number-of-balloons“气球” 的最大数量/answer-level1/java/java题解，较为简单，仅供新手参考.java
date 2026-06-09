        int b = text.length() - text.replace("b", "").length();
        int a = text.length() - text.replace("a", "").length();
        int l  = (text.length() - text.replace("l", "").length())/2;
        int o = (text.length() - text.replace("o", "").length())/2;
        int n = text.length() - text.replace("n", "").length();
        int [] arr = new int[]{b,a,l,o,n};
        Arrays.sort(arr);