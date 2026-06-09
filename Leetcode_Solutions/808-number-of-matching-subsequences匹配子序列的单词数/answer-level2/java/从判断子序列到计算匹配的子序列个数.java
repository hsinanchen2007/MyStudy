class Solution {
    public int numMatchingSubseq(String S, String[] words) {
      boolean bb;
      int count=0;
      for(String y:words){    /*遍历words字符串数组*/
          bb=son(y,S);        /*逐一判断是否为子序列*/
          if(bb){
            count++;          /*统计匹配的子序列的个数*/
          }
      }
      return count;
    }
    /*判断字符串t是否为字符串s的子序列--来自判断子序列题的解法*/ 
  /*indexOf方法：:int indexOf(String str, int fromIndex): 返回从 fromIndex 位置开始查找指定字符在字符串中第一次出现处的索引，如果此字符串中没有这样的字符，则返回 -1。*/ 
    boolean son(String t,String s){ 
        int i=-1;
        for(int k=0;k<t.length();k++){
            i=s.indexOf(t.charAt(k),i+1);    /*查找子串*/
            if(i==-1){
               return false;
            }
        }
        return true;
    }
}