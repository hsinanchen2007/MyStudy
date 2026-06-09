```
public int thirdMax(int[] nums) {
        Set<Integer> set=new TreeSet<>();
        int max=0;
        for(int i:nums){
            set.add(i);
            max=Math.max(max, i);
        }
        int sz=set.size();
        Iterator<Integer> iterator=set.iterator();
        while(iterator.hasNext()&&sz>3){
            sz--;
            iterator.next();
        }
        return sz==3?iterator.next():max;
    }
```
