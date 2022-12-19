class Solution {
    public int strStr(String haystack, String needle) {
        int len1=haystack.length();
        int len2=needle.length();
        if (len2>len1){
            return -1;
        }
        if (len2==0){
            return 0;
        }

        HashMap <Character,Integer> calShiftMap=new HashMap<Character,Integer> ();//偏移表的建立
        for (int i=0;i<len2;i++){
            calShiftMap.put(needle.charAt(i),(len2-i));
        }

        int idx=0; //当前查询索引

        while(idx+len2<=len1){
            String strCut=haystack.substring(idx,idx+len2);

            if (strCut.equals(needle)){
                return idx;
            }

            else{
                if (idx+len2==len1){
                    return -1;
                } //已经做到最后一组了
                else if(idx+len2<len1){
                    char next_char=haystack.charAt(idx+len2);
                    if (needle.indexOf(next_char)>=0){
                        idx+=calShiftMap.get(next_char);
                    }
                    else{
                        idx+=len2+1;
                    }
                }
            }
        }
        return -1;
    }
}