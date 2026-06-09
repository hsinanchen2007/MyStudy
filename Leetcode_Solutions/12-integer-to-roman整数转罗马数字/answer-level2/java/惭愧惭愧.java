```
public String intToRoman(int num) {
        StringBuilder res = new StringBuilder();
        String[] strs = new String[]{"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int[] nums = new int[]{1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

        for (int i = nums.length-1; i >= 0; i--) {
            if (num / nums[i] > 0){
                int count = num / nums[i];
                for (int j = 0; j < count; j++) {
                    res.append(strs[i]);
                }
                num = num - count * nums[i];
            }
        }
        return res.toString();
    }
```
