[Leetcode-Java(200+题解，持续更新、欢迎star)](https://github.com/pphdsny/Leetcode-Java/blob/master/src/pp/arithmetic/leetcode/_448_findDisappearedNumbers.java)

```java
    /**
     * 解题思路：
     * 简单求解:用一个hash映射表保存出现过的数字，再遍历保存结果找出未出现的数字（使用了O(n)的额外空间）==>{findDisappearedNumbers2}
     * <p>
     * 优化求解：去除O(n)的空间
     * 1.遍历nums,将item对应的位置+n，用于标识是否出现过（注意对item取模）
     * 2.再次遍历nums，找到小于n的位置就是未出现的数字了
     *
     * @param nums
     * @return
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> retList = new ArrayList<>();

        int n = nums.length;
        for (int i = 0; i < n; i++) {
            int index = (nums[i] - 1) % n;
            nums[index] += n;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                retList.add(i + 1);
            }
        }

        return retList;
    }

    public List<Integer> findDisappearedNumbers2(int[] nums) {
        List<Integer> retList = new ArrayList<>();
        boolean[] allNums = new boolean[nums.length];
        for (int i = 0; i < nums.length; i++) {
            allNums[nums[i] - 1] = true;
        }
        for (int i = 0; i < allNums.length; i++) {
            boolean item = allNums[i];
            if (!item) retList.add(i + 1);
        }
        return retList;
    }
```