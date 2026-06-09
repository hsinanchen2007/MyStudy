递归来数原子数量
遍历字符串 遇见'('使用栈的思想，找到其对应的')'的下标，递归遍历'('和')'之间的字符串，使用map保存

需要注意的是，递归要保存上一层括号对应的总倍数

```
class Solution {
    Map<String,Integer> map = new HashMap<>(); 
    public String countOfAtoms(String formula) {
        if(formula.isEmpty()) return "";
        dfs(formula,1);
        PriorityQueue<String> pq = new PriorityQueue<String>((a,b)->a.compareTo(b));
        StringBuilder res = new StringBuilder();
        for(String key : map.keySet()){
            if(map.get(key)>1){
                pq.offer(key + map.get(key));
            } else{
                pq.offer(key);
            }            
        }
        while(!pq.isEmpty()){
            res.append(pq.poll());
        }
        return res.toString();
    }
    //num表示上一层括号对应的倍数
    public void dfs(String str,int num){
        if(str.equals("")) return;
        
        int left = 0;
        
        for(int i=0 ; i<str.length() ;){
            char c = str.charAt(i);
            if(isUpper(c)){
                i++;
                int count = 1;
                String key= String.valueOf(c);
                if(i<str.length() && isLower(str.charAt(i))){
                    key += str.charAt(i);
                    i++;
                }
                StringBuilder tmp = new StringBuilder();
                while(i<str.length() && isNum(str.charAt(i))){
                    tmp.append(str.charAt(i));
                    i++;
                }
                String s = tmp.toString();
                if(!s.isEmpty()){
                    count = Integer.parseInt(s);
                }
                map.put(key,map.getOrDefault(key,0)+count*num);
            } else if(c=='('){
                i++;
                int start = i;
                int l = 1;
                while(i<str.length() && l>0){
                    if(str.charAt(i)=='('){
                        ++l;
                    } else if(str.charAt(i)==')'){
                        --l;
                    }
                    ++i;
                }
                int end = i;
                StringBuilder tmp = new StringBuilder();
                while(i<str.length() && isNum(str.charAt(i))){
                    tmp.append(str.charAt(i));
                    i++;
                }
                dfs(str.substring(start,end),num*Integer.parseInt(tmp.toString()));
            } else{
                ++i;
            }
        }
        
    }
    
    public boolean isUpper(char c){
        return c>='A' && c<='Z';
    }
    public boolean isLower(char c){
        return c>='a' && c<='z';
    }
    public boolean isNum(char c){
        return c>='0' && c<='9';
    }
}
```
