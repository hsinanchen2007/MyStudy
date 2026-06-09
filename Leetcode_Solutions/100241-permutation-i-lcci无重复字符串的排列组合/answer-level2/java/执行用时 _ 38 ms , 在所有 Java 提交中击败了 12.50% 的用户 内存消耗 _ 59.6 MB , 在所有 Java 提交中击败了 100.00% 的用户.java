```
class Solution {
    public String[] permutation(String S) {
        if(S==null||S.length()==0) {
            return new String[0];
        } else {
           String[] strs = S.split("");
           List<String> calculateList = new ArrayList<>();
           
           for (String str: strs) {
                calculateList = getResult(calculateList, str);
           }
            return calculateList.toArray(new String[0]);
        }
    }

    public List<String> getResult(List<String> list, String s) {
        // System.out.println(s);
        if(list.size()==0) {
            list.add(s);
            return list;
        } else {
            List<String> newList = new ArrayList<>();
            for(String str:list) {
                for(int i=0;i<str.length();i++) {
                    // System.out.println(str.substring(0,i));
                    // System.out.println(str.substring(i,str.length()));
                    String newStr = str.substring(0,i) + s + str.substring(i,str.length());
                    newList.add(newStr);
                }
                newList.add(str+s);
            }
            return newList;
        }
        
    }
}
```
