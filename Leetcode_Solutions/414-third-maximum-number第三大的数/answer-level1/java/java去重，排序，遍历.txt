```
public int thirdMax(int[] nums) {
        Set<Integer> set = new HashSet<>();
        for(int data : nums) {
            set.add(data);
        }
        int[] newArr = new int[set.size()];
        int a = 0;
        for(int data : set) {
            newArr[a++] = data;
        }
        Arrays.sort(newArr);
//此时的newArr是去重，并且是有序的
        if(newArr.length < 3) {
            return newArr[newArr.length - 1];
        }

        if(newArr.length >= 3) {
            return newArr[newArr.length - 3];
        }

        return -1;
    }
```
