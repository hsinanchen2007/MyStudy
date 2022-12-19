```
    public int removeDuplicates(int[] nums) {
        Set<Integer> set=new LinkedHashSet<>();
        for (int num : nums) {
            set.add(num);
        }
        Iterator<Integer> iterator=set.iterator();
        int i=0;
        while (iterator.hasNext()){
            nums[i++]=iterator.next();
        }
        return i;
    }
```
