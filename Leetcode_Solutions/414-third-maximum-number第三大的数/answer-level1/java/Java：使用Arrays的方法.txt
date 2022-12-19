```
public static int thirdMax(int[] nums) {
        int[] arr = Arrays.stream(nums).distinct().toArray();
        Arrays.sort(arr);
        if(arr.length<3)
            return arr[arr.length-1];
        else
            return arr[arr.length-3];
    }
```
