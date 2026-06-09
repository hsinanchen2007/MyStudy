public int strStr(String haystack, String needle) {
    if(needle.length() == 0){
        return 0;
    }
    if(!haystack.contains(needle)){
        return -1;
    }else{
        return haystack.indexOf(needle);
    }
}