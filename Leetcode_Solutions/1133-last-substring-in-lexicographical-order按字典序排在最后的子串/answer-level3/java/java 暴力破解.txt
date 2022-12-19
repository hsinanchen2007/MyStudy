
主要思路就是找到最大的字母，如果字母相同再进行下一位的比较，如果有什么问题，欢迎大佬在评论区指摘
```
    public String lastSubstring(String s) {
        int maxValue=s.charAt(0)-'a';
        int maxIndex=0;
        for(int i=1;i<s.length();i++){
            char c=s.charAt(i);
            if(c-'a'>maxValue){
                maxValue=c-'a';
                maxIndex=i;
            }else if(c-'a'==maxValue){
              int  newMaxIndex=getMaxIndex(maxIndex,i,s);
              if(newMaxIndex==-1){
                  /*防止都是重复字符，一下子超时了*/
                  return s.substring(maxIndex);
              }
                maxIndex=newMaxIndex;
            }
        }
        return s.substring(maxIndex);
    }
    private int getMaxIndex(int curMaxIndex,int newMaxIndex,String s) {
        int i = 1;
        while (newMaxIndex + i < s.length()) {
            if (s.charAt(curMaxIndex + i) > s.charAt(newMaxIndex + i)) {
                return curMaxIndex;
            } else if (s.charAt(curMaxIndex + i) < s.charAt(newMaxIndex + i)) {
                return newMaxIndex;
            } else {
                i++;
            }
        }
        return -1;
    }
```
