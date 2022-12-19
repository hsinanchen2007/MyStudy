执行结果：
通过
显示详情
执行用时 :
1 ms
, 在所有 Java 提交中击败了
99.64%
的用户
内存消耗 :
35.7 MB
, 在所有 Java 提交中击败了
31.17%
的用户
```
class Solution {
    List<String> res = new ArrayList<String>();
    public List<String> fullJustify(String[] words, int maxWidth) {
        int len = words.length;
        
        int count=0;
        List<String> temp = new ArrayList<String>();
        for(int i=0; i<len; i++){
            String s = words[i];
            count+=s.length();
            if(count<=maxWidth){
                temp.add(s);
            }else{
                count-=s.length();
                res.add(process(temp,maxWidth,count-1,false));
                count=0;
                temp =  new ArrayList<String>();
                temp.add(s);//this is because no words longer than maxWidth
                count+=s.length();
            }
            count++;
        }
        res.add(process(temp,maxWidth,count-1,true));
        return res;
    }
    private String process(List<String> list, int maxWidth,int count,boolean last){
        int spaces = maxWidth-count;
        int size=list.size()-1;
        StringBuffer sb = new StringBuffer();
        if(size==0){
            sb.append(list.get(0));
            for(int i=0; i<spaces; i++){
                sb.append(" ");
            }
            return sb.toString();
        }
        if(last){
           int index = 0;
           for(String s:list){
                sb.append(s);
               if(index++==size){
                   for(int i=0; i<spaces; i++){
                        sb.append(" ");
                    }
                    return sb.toString();
               }else{
                   sb.append(" ");
               }
            } 
        }
        
        int average = spaces/size;
        int remainder = spaces%size;
        
        int index = 0;
        
        for(String s:list){
            sb.append(s);
            
            if(index++==size)return sb.toString();
            sb.append(" ");
            for(int i=0; i<average; i++){
                sb.append(" ");
            }
            if(remainder>0){
                sb.append(" ");
                remainder--;
            }
        }
        return null;
    }
}
```
