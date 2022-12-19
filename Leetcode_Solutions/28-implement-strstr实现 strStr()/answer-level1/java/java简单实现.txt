public int str(String haystack, String needle){

        int a =haystack.length ();
        int b = needle.length ();
        if (b==0){
            return 0;
        }
        if (a<b){
            return -1;
        }
        return haystack.indexOf ( needle );
    }