我的想法是这道题符合辅助空间，所以可以用这种空间换时间。
```
public static List<Integer> findDisappearedNumbers(int[] nums) {
        int length = nums.length;
        int[] arrays = new int[length+1];
        List<Integer> integerList = new ArrayList<>(length);
        for (int i = 0; i < length; i++) {
            arrays[nums[i]]++;
        }
        for (int i = 1; i <= length; i++) {
            if (arrays[i] == 0){
                integerList.add(i);
            }
        }
        return integerList;
    }
```


