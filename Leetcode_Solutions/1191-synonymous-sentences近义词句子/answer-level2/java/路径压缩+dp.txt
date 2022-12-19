```
class Solution {
    private HashMap<String,String> hash;
    public List<String> generateSentences(List<List<String>> synonyms, String text) {
        hash = new HashMap<>();
        for(List<String> list:synonyms){
            for(String item:list){
                hash.put(item,item);
            }
        }
        for(List<String> list:synonyms){
            String str1 = list.get(0);
            String str2 = list.get(1);
            if(!find(str1).equals(find(str2))){
                union(str1,str2);
            }
        }
        List<String> res = new ArrayList<>();
        res.add("");
        String[] strs = text.split(" ");
        for(int i=strs.length-1;i>=0;i--){
            String item = strs[i];
            if(hash.containsKey(item)){
                List<String> temp = new ArrayList<>();
                List<String> words = getList(item);
                for(String word:words){
                    temp.addAll(addition(word,res));
                }
                res = temp;
            }else{
                List<String> temp = new ArrayList<String>();
                for(String strItem:res){
                    if(strItem.length()==0){
                        strItem = item;
                    }else{
                        strItem = item+" "+strItem;
                    }
                    temp.add(strItem);
                }
                res = temp;
            }
        }
        Collections.sort(res);
        return res;
    }
    private List<String> addition(String item,List<String> src){
        List<String> res = new ArrayList<>();
        for(String strItem:src){
            if(strItem.length()==0){
                res.add(item);
            }else{
                res.add(item+" "+strItem);
            }
            
        }
        return res;
    }
    private List<String> getList(String tar){
        String key = hash.get(tar);
        List<String> res = new ArrayList<>();
        for(Map.Entry<String,String> entry:hash.entrySet()){
            if(entry.getValue().equals(key)){
                res.add(entry.getKey());
            }
        }
        return res;
    }
    private String find(String start){
        if(!hash.get(start).equals(start)) return find(hash.get(start));
        return start; 
    }
    private String union(String str1,String str2){
        String top1 = find(str1);
        String top2 = find(str2);
        if(top1.equals(top2)){
            return top1;
        }
        String pre = "",cur = str2;
        while(!pre.equals(top1)){
            pre = hash.get(cur);
            hash.put(cur,top1);
            cur = pre;
            pre = hash.get(cur);
        }
        return top1;
    }
}
```
