```
        int len = nums.length;
        int[] numsCopy = new int[len];
        System.arraycopy(nums, 0, numsCopy, 0, len);

        for(int i = 0; i < len; i++) {
            nums[(i + k) % len] = numsCopy[i];
        }
```
