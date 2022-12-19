```
class Solution {
    public List<String> generatePossibleNextMoves(String s) {
        List<String> ls = new ArrayList<>();
        for(int i=0; i<s.length()-1; ++i){
            if(s.charAt(i)=='+'&&s.charAt(i+1)=='+'){
                StringBuilder sb = new StringBuilder(s);
                sb.setCharAt(i,'-');
                sb.setCharAt(i+1,'-');
                String str = sb.toString();
                ls.add(str);
            }
        }
        return ls;
    }
}
```

