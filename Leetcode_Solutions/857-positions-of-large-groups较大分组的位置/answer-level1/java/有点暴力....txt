```
class Solution {
    public List<List<Integer>> largeGroupPositions(String S) {
        int i=0;
        List<List<Integer>> li=new ArrayList<>();
       while(i<S.length())
       {
          int j=i+1;
          int count=1;
          for(;j<S.length();j++)
          {
              if(S.charAt(j)==S.charAt(i))
                 count++;
              else break;
          }
          if(count>=3)
          {
             List<Integer> subList=new ArrayList<>();
             subList.add(i);
             subList.add(i+count-1);
             li.add(subList);
          }
          i+=count;
       }
       return li;
    }
}
```
