使用双指针的形式，一个指针b用于存储，一个指针i用于向前遍历
另外定义一个数量记录器cnt，用于根据数量判断两个指针的走向

1. 当i向前走的时候，第一个数字肯定存入，此时cnt=1，第一种情况只需要判断从1开始的第一个数是否等于自己
等于的话,nums[++b] = nums[i],且此时cnt+=1

2. 第二种情况如果i与b处存放的值不等，而此时cnt又满足小于2，直接存，且将cnt置为1，因为此时的b处是第一个

3. 如果cnt依据第一种情况，cnt=2了，此时不满足小于2，说明后面只有遇到不等自己才会存，所以判断条件为遇到不等于b处存储的值，此时才向前走，等同于第二种情况。

整体代码如下：
```java
    // 重复的元素最多出现两次
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int b = 0;
        int cnt = 1;
        for (int i = 1; i < nums.length; i++) {
            // 如果两者相等，此时cnt=2,如果再遇到1，此时为3
            if ((cnt < 2)) {
                if (nums[i] == nums[b]) {
                    // 如果数量没到2,且相等，存放，数量+1
                    nums[++b] = nums[i];
                    cnt += 1;
                } else {
                    // 如果不相等，直接存放，数量置为1
                    nums[++b] = nums[i];
                    cnt = 1;
                }
            } else {
                // 如果数量>=2，只有遇到不等的时候才存放，否则一直向前走
                if (nums[i] != nums[b]) {
                    nums[++b] = nums[i];
                    cnt = 1;
                }
            }
        }
        // 注意要想把b个元素打印出来，最后返回的要是b+1,因为b从0开始
        return b + 1;
    }
```