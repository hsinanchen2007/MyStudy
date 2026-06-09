看了下题解，发现问题被变得复杂，贴一下我的答案，给大家点参考。
```

class Solution {
    public List<String> letterCasePermutation(String S) {
        if(S==null || S.length()==0) return new ArrayList<String>();
        List<String> result = new ArrayList<String>();
        helper(S,"",result,0);
        return result;
    }
    
    private void helper(String S,String str,List<String> result,int index){
        if(S.length()==index){
            result.add(str);
            return;
        }
        char c = S.charAt(index);
        helper(S,str+String.valueOf(c),result,index+1);
        if('a'-1<c&&c<'z'+1){
            str += String.valueOf((char)(c-32));   
            helper(S,str,result,index+1);     
        }else if('A'-1<c&&c<'Z'+1){
            str += String.valueOf((char)(c+32));
            helper(S,str,result,index+1);
        }  
    }
}
```
