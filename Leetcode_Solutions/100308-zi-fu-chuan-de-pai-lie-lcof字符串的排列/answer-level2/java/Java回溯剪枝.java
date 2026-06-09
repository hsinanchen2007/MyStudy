吐槽一下这个Java版方法，居然输入一个字符串，再返回一个字符串数组，正常题肯定是输入一个数组，返回一个二维列表吧，这个输入和输出也太脑瘫了
```
class Solution {
    public String[] permutation(String s) {
      StringBuilder sb = new StringBuilder();
      List<String> list = new ArrayList();
      boolean[] v = new boolean[s.length()];
      char[] ch = s.toCharArray();
      Arrays.sort(ch);
      helper(ch,list,sb,0,v);
      String[] str = new String[list.size()];
      for(int i=0;i<list.size();i++) str[i]=list.get(i);
      return str;
    }

    private void helper(char[] ch,List list,StringBuilder sb,int len,boolean[] v)
    {
      if(len==ch.length){
        list.add(new StringBuilder(sb).toString());
        return;
      }
      for(int i=0;i<ch.length;i++){
        if(!v[i]){
          if(i>0 && ch[i-1]==ch[i] && !v[i-1]) continue;
          sb.append(ch[i]);
          v[i]=true;
          helper(ch,list,sb,len+1,v);
          v[i]=false;
          sb.deleteCharAt(sb.length()-1);
        }
      }
    }
}
```
