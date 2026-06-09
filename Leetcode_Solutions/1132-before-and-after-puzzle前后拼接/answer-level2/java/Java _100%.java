```
class Solution {
    public List<String> beforeAndAfterPuzzles(String[] phrases) {
        Map<String,List<Integer>> map=new HashMap<>();
        Set<String> seen=new HashSet<>();
        List<String> output=new ArrayList<>();

        for (int i=0;i<phrases.length;i++){
            String temp=phrases[i].indexOf(" ")==-1?phrases[i]:phrases[i].substring(0,phrases[i].indexOf(" "));
            if (!map.containsKey(temp)){
                map.put(temp,new ArrayList<Integer>());
            }
            map.get(temp).add(i);
        }

        for (int i=0;i<phrases.length;i++){
            String temp=phrases[i].lastIndexOf(" ")==-1?phrases[i]:phrases[i].substring(phrases[i].lastIndexOf(" ")+1);
            if (map.containsKey(temp)){
                List<Integer> list=map.get(temp);
                for (int j=0;j<list.size();j++){
                    if (list.get(j)==i){
                        continue;
                    }
                    String tobeadd=phrases[i].substring(0,phrases[i].length()-temp.length())+phrases[list.get(j)];
                    if (!seen.contains(tobeadd)){
                        output.add(tobeadd);
                        seen.add(tobeadd);
                    }
                }
            }
        }
        Collections.sort(output,(String a,String b)->a.compareTo(b));
        return output;
    }
}
```
