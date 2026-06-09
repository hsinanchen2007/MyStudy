```java
class Solution {
   List<List<String>> res= new ArrayList<>();
    public List<List<String>> partition(String s) {
        backtrack(s,0,new ArrayList<String>());
        return res;
    }
    //回溯，start代表每一次尝试开始位置
    public void backtrack(String s,int start,List<String> list){
        if(start == s.length()){
            res.add(new ArrayList<>(list));
            return;
        }
        for(int end=start;end<s.length();end++){
            if(isValid(s,start,end)){
                list.add(s.substring(start,end+1));
                backtrack(s,end+1,list);
                list.remove(list.size()-1);
            }else{
                continue;
            }
        }
    }

    //判断是否为回文，双指针比较
    private boolean isValid(String s, int start, int end) {
        int i=start;
        int j=end;
        while(i<1+start+(end-start)/2){
            if(s.charAt(i)==s.charAt(j)){
                i++;
                j--;
                continue;
            }else{
                return false;
            }
          
        }
        return true;
    }
}
```