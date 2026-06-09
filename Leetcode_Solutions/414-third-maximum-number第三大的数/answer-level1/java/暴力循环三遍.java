```java
public int thirdMax(int[] nums) {
        LinkedList<Integer> list = new LinkedList<Integer>();
        int[] ans1 = findMax(nums, list);
        list.add(ans1[0]);
        int[] ans2 = findMax(nums, list);
        list.add(ans2[0]);
        int[] ans3 = findMax(nums, list);
        if(ans3[1] > 0)
            return ans3[0];
        return ans1[0];
    }

    private int[] findMax(int[] nums, LinkedList<Integer> list){
        int max = Integer.MIN_VALUE;
        int cnt = 0;
        for(int val : nums)
            if(check(val, list))
                max = Math.max(max, val);
        for(int val : nums)
            if(check(val, list) && val == max)
                cnt++;
        return new int[] {max, cnt};
    }

    private boolean check(int num, LinkedList<Integer> list){
        if (list.isEmpty())
            return true;
        for(int val : list)
            if(val == num)
                return false;
        return true;
    }
```