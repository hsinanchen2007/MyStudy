思路：
1.一段一段往后截取
2.当以｛开头的时候要截取一整段，以｛和｝个数相等判断结束位置，开头和结尾的大括号不要留
3.考虑截取后剩下来的字符串有三种情况：字母开头、｛开头、逗号开头
4.当截剩下的字符串以逗号开头时，表示该逗号左右两段是并列的了，要取并集
5.每截取一段取作一个list与前一段对应的list交叉组合成一个新list,以此往后类推
6.每一段如果包含｛｝，则调用递归返回一个list。
测试和本地运行都可以，却提交不过，我吐了。
class Solution {

    public List<String> braceExpansionII(String expression) {
        List<String> list = new ArrayList<String>();
        list = helper(expression);
        Map<String,String> map = new HashMap<String,String>();
        Iterator it = list.iterator();
        for(int i = 0; i < list.size(); i++){
            String item = list.get(i);
            if(map.containsKey(item)){
                list.remove(i--);
            }
            map.put(item,"");
        }
        return list;
     }

    public List<String> helper(String s){
        List<String> list = new ArrayList<String>();   
        int i=0;
        int left=0;
        int right=0;
        while(i<s.length()){
            if(s.charAt(0)!='{'&&s.charAt(0)!=','){
                String sTemp = "";
                if(s.indexOf("{")!=-1){
                   sTemp = s.substring(0,s.indexOf("{"));
                   s=s.substring(s.indexOf("{"));
                   i=0;
                }else{
                   sTemp = s;
                   s="";
                   i=0;
                }
                if(list.size()==0){
                    list.add(sTemp);
                    continue;
                }
                List<String> listTemp = new ArrayList<String>();
                Iterator<String> it = list.iterator(); 
                while(it.hasNext()){
                    listTemp.add(it.next()+sTemp);
                }
                list = listTemp;
            }else if(s.charAt(0)=='{'){
                if(s.charAt(i)=='{'){
                    left++;
                    i++;
                }else if(s.charAt(i)=='}'){
                    right++;
                    if(right==left){
                        String sTemp = s.substring(1,i);
                        List<String> listTemp = new ArrayList<String>();
                        List<String> listNext = new ArrayList<String>();
                        if(sTemp.indexOf("{")!=-1){
                            listNext  = helper(sTemp);
                        }else{
                            listNext = Arrays.asList(sTemp.split(","));
                            listNext = new ArrayList(listNext);
                        }
                        if(list.size()==0){
                            listTemp=listNext;
                        }else{
                            for(int m=0;m<list.size();m++){
                                for(int n=0;n<listNext.size();n++){
                                    listTemp.add(list.get(m)+listNext.get(n));
                                }
                            }
                        }
                        list = listTemp;
                        s=s.substring(i+1);
                        i=0;
                        left=0;
                        right=0;
                        continue;
                    }
                    i++;
                }else{
                    i++;
                } 
            }else if(s.charAt(0)==','){
                List<String> listNext = new ArrayList<String>();
                listNext = helper(s.substring(1));
                Iterator<String> it = listNext.iterator();
                while(it.hasNext()){
                    list.add(it.next());
                }
                s="";
                i=0;
            }            
        }
        return list;
    }    
}