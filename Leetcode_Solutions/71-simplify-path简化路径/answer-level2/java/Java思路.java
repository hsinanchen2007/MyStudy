```
class Solution {
    public String simplifyPath(String path) {
        String[] str = path.split("/");
        
        ArrayList<String> list = new ArrayList();       
        for(String s : str){
            if(s.equals("") || s.equals(".")){
                continue;
            }
            if(s.equals("..")){
                if(!list.isEmpty()){
                    list.remove(list.size() - 1);
                }else{
                    continue;
                }
            }else{
                list.add(s);
            }
        }
        
        if(list.isEmpty()) return "/";
        
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < list.size(); i++){
            sb.append("/" + list.get(i));
        }
        
        return sb.toString();
    }
}
```
