### 思路一： 借用TreeSet（红黑树） O(n)
比较好想的思路
1. 维护一个只有3个元素的TreeSet，如果大于三个元素就就把Set中的最小最小值remove掉。
2. 最后如果Set中元素小于3就返回Set最大值，否则返回最小值。

时间复杂度： O(n * log3) == O(n)
```java []
class Solution {
    public int thirdMax(int[] nums) {
        if (nums == null || nums.length == 0) throw new RuntimeException("error");

        TreeSet<Integer> set = new TreeSet<>();
        for (Integer elem : nums) {
            set.add(elem);
            if (set.size() > 3) set.remove(set.first());
        }
        
        return set.size() < 3 ? set.last() : set.first();   // set.last() 里面最大的元素
    }
}
```

### 思路二： 
1. 用三个变量来存放第一大，第二大，第三大的元素的变量，分别为one, two, three；
2. 遍历数组，若该元素比one大则往后顺移一个元素，比two大则往往后顺移一个元素，比three大则赋值个three；
3. 最后得到第三大的元素，若没有则返回第一大的元素。

```java []
class Solution {
    private long MIN = Long.MIN_VALUE;    // MIN代表没有在值
    
    public int thirdMax(int[] nums) {
        if (nums == null || nums.length == 0) throw new RuntimeException("nums is null or length of 0");
        int n = nums.length;
        
        int one = nums[0];
        long two = MIN;
        long three = MIN;
        
        for (int i = 1; i <  n; i++) {
            int now = nums[i];
            if (now == one || now == two || now == three) continue;    // 如果存在过就跳过不看
            if (now > one) {
                three = two;
                two = one;
                one = now;
            } else if (now > two) {
                three = two;
                two = now;
            } else if (now > three) {
                three = now;
            }
        }

        if (three == MIN) return one;  // 没有第三大的元素，就返回最大值
        return (int)three;
    }
}
```


