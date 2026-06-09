```
class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> result = new ArrayList<>();
        if(s.trim().length()<4){
            return result;
        }
        restoreIpAddress(result,new ArrayList<Integer>(),s,1);
        return result;
    }
    
    private void restoreIpAddress(List<String> result, List<Integer> curr,String s, int start){
        if(curr.size()==3){
            if(curr.get(0)-0<=3&&curr.get(1)-curr.get(0)<=3&&curr.get(2)-curr.get(1)<=3&&s.length()-curr.get(2)<=3) {
            StringBuilder sb = new StringBuilder();
        sb.append(s.substring(0,curr.get(0))).append(".").append(s.substring(curr.get(0),curr.get(1))).append(".").append(s.substring(curr.get(1),curr.get(2))).append(".").append(s.substring(curr.get(2),s.length()));
           if(isIp(sb.toString())){
                result.add(new String(sb.toString()));   
           }
            }
        }else{
           for(int i = start;i<s.length()&&i<start+3;i++){
               curr.add(i);
               restoreIpAddress(result,curr,s,i+1);
               curr.remove(curr.size()-1);
           }
        }
        
    }
    
    
    private boolean isIp(String s){
        String[] aArr = s.split("\\.");
        if(aArr.length==4){
            for(int i  =0;i<4;i++){
                if(!(Integer.valueOf(aArr[i])>=0&&Integer.valueOf(aArr[i])<=255&&aArr[i].length()==String.valueOf(Integer.valueOf(aArr[i])).length()))
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
}
```
