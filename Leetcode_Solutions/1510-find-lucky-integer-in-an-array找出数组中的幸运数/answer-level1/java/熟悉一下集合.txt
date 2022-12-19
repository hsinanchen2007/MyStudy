```
class Solution {
    public int findLucky(int[] arr) {
        Set<Integer> hs = new HashSet();
        for(int i: arr){
            hs.add(i);
        }
        Map<Integer,Integer> hm = new HashMap();
        for(Iterator<Integer> it = hs.iterator();it.hasNext();){
            hm.put(it.next(),0);
        }
        for(int i : arr){
            hm.put(i,hm.get(i)+1);
        }
        List<Integer> ls = new ArrayList();
        for(Iterator<Integer> it = hs.iterator();it.hasNext();){
            int i = it.next();
            if(i == hm.get(i)) ls.add(i);
        }
        Comparator numComparator = new numComparator();
        Collections.sort(ls,numComparator);
        return ls.size()==0?-1:ls.get(0);
    }
}

class numComparator implements Comparator<Integer>{
    @Override
    public int compare(Integer num1 , Integer num2){
        return (num1-num2)>0 ? -1:1;
    }
}
```
