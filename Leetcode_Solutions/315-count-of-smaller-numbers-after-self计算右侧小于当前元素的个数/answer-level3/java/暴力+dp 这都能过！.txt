   
```
 public List<Integer> countSmaller(int[] nums) {
        
        int[] res = new int[nums.length];
        TreeMap<Integer, Integer> moneyCount = new TreeMap<>((m1, m2) -> m2 - m1);
    

        for (int i = nums.length -1 ; i >= 0;  i--) {
            int count = 0;
            for (int j = i+1 ; j < nums.length;  j++ ) {
                 if(nums[j] < nums[i]){
                     count++;
                 }
                 if(nums[i] == nums[j]){
                     count += res[j];
                     break;
                 }

            }
            res[i] = count;
        }
        return Arrays.stream(res).boxed().collect(Collectors.toList());
    }
```


执行用时 : 451 ms  , 在所有 java 提交中击败了 9.69% 的用户
内存消耗 :39.8 M , 在所有 java 提交中击败了95.45%的用户