可以继续优化

```
class Solution {
    private List<Integer> output = new ArrayList<Integer>();
    
    public List<Integer> findSubstring(String s, String[] words) {
        if (s.length()==0 || words.length==0)
            return new ArrayList();
        // if (s==null || words==null)
        //     return new ArrayList();
        
        List<String> list = new ArrayList<String>();
        for (int i = 0; i < words.length; ++i) {
            list.add(words[i]);
        }
        goback(s, "", list);
        List<Integer> finOut = new ArrayList<Integer>();
        for (Integer i: output) {
            if (!finOut.contains(i))
                finOut.add(i);
        }
        return finOut;
    }
    
    private void goback(String s, String combine, List<String> words) {
        // if (words.size()==0)
            
        
        if (words.size() == 0 && s.contains(combine)) {
            // List<Integer> tmpList = new ArrayList() {{
            //     add(s.indexOf(combine));
            //     add(s.indexOf(combine)+combine.length());
            // }};
            List<Integer> res = new ArrayList();
            allIndexOf(s,combine,0,res);
            for (Integer i: res) {
                output.add(i);
            }
            // output.add();
        }
        // System.out.print(words.get(0).getClass().getName());
        for (int i = 0; i < words.size(); ++i) {
            
            List<String> tmpWord = new ArrayList<String>();
            tmpWord.addAll(words);
            tmpWord.remove(i);
            // System.out.print(tmpWord.get(i)+","+i+","+words.size()+";");
            goback(s, combine+words.get(i), tmpWord);
        }
        
    }
    
    private  void allIndexOf(String a, String b, int off, List<Integer> res) {
        off = a.indexOf(b,off);
        if (off!=-1) {
            res.add(off);
            allIndexOf(a,b,++off,res);
        }
    }
}
```
