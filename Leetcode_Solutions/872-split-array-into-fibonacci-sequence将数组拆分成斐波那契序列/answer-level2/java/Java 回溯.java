```
class Solution {
    List<Integer> list = new ArrayList<>();
    List<Integer> res = null;

    public List<Integer> splitIntoFibonacci(String S) {
        dfs(S,0);
        return res == null ? new ArrayList<>() : res;
    }

    private void dfs(String s, int start){
        if(res != null){
            return;
        }

        if(start == s.length()){
            if(list.size() >= 3){
                res = new ArrayList<>(list);
            }
            return;
        }
        
        // 如果是 0 开头，那么只能是 0
        if(s.charAt(start) == '0'){
            if(list.size() >= 2){
                int a = list.get(list.size()-2);
                int b = list.get(list.size()-1);
                if(a+b != 0){
                    return;
                }
            }
            list.add(0);
            dfs(s,start+1);
            list.remove(list.size()-1);
            return;
        }

        for(int i=start+1;i<=s.length();i++){
            String cur = s.substring(start,i);
            int val;
            try{
                val = Integer.valueOf(cur);
            }catch(Exception e){
                // 超出 Integer 最大值
                break;
            }

            if(list.size() >= 2){
                int a = list.get(list.size()-2);
                int b = list.get(list.size()-1);
                if(a+b > val){
                    continue;
                }else if(a+b < val){
                    break;
                }
            }
            list.add(val);
            dfs(s,i);
            list.remove(list.size()-1);
        }
    }

}
```
