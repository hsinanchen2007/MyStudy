```java
    //方法1， 位运算
    public static int missingNumber(int[] nums) {
        int result = 0;
        for (int i = 0; i < nums.length; i++) {
            result = result ^ (i+1) ^ nums[i];
        }
        return result;
    }

    //方法2，hash表
    public static int missingNumber2(int[] nums) {
        int result = 0;
        //Set<Integer> numsSet = new HashSet<>();
        //List<Integer> numsSet = new LinkedList<>();
        //List<Integer> numsSet = new ArrayList<>();
        List<Integer> numsSet = new Vector<>();
        for (int num : nums) {
            numsSet.add(num);
        }
        for (int i = 0; i <= nums.length; i++) {
            if (!numsSet.contains(i)) {
                result = i;
                break;
            }
        }
        return result;
    }
```