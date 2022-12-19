```
class Solution {
    public int minimumLengthEncoding(String[] words) {
        int len=words.length;
        if(len==1) return words[0].length()+1;
        List<String> list=new ArrayList<>();
        for(String s:words){
            if(list.isEmpty()){
                list.add(s);
            }
            else{
                 boolean flag=false;
                 int lens=s.length();
                 for(int i=0;i<list.size();i++){
                     String tem=list.get(i);
                     int lent=tem.length();
                     if(lent==lens){
                        if(tem.equals(s)){
                            flag=true;
                            break;
                        } 
                     }
                     else if(lent<lens){
                         if(s.substring(lens-lent).equals(tem)){
                             list.remove(i);
                             list.add(s);
                             flag=true;
                             break;
                         }
                     }
                     else{
                         if(tem.substring(lent-lens).equals(s)){
                             flag=true;
                             break;
                         }
                     }
                 }
                 if(!flag) list.add(s);
            }
        }
    int lensum=0;
    for(String ss:list){
        lensum+=ss.length();
    }
    return lensum+list.size();
    }
}
```
