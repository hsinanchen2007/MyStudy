如果不能把简单代码复杂化，那么Java将毫无意义。
![image.png](https://pic.leetcode-cn.com/6f043f45fe97127f22a7a19454a95258e672cfe646098a4ed6f85db512a09b77-image.png)

# 代码

```java
class Solution {
    /**
     * 题目地址：https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
     * -------------------------------------------------------------------
     * 思考： 适配规则
     *  Q:如果问题改成正负数、或者其他分区规则如何适配?
     *  A:使用工厂方法，需要添加新规则时。
     *      只需实现Rule接口，添加具体规则，以及实现RuleFactory，添加具体规则的创建工厂
     * -------------------------------------------------------------------
     * 思路：双指针交换奇偶
     * -------------------------------------------------------------------
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    public int[] exchange(int[] nums) {
        RuleFactory ruleFactory = new OddEvenRuleFactory();
        return exchange(nums, ruleFactory.getRule());
    }

    public int[] exchange(int[] nums, Rule rule) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            // left指向分区2
            while (left < right && rule.judge(nums[left])) {
                left++;
            }
            // right指向分区1
            while (left < right && !rule.judge(nums[right])) {
                right--;
            }
            if (left < right) {
                int temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        return nums;
    }
    
    // 抽象规则
    public interface Rule {
        boolean judge(int num);
    }

    // 具体规则
    static class OddEvenRule implements Rule {
        @Override
        public boolean judge(int num) {
            return (num & 1) == 1;//奇数true
        }
    }

    // 工厂方法 抽象工厂类
    abstract static class RuleFactory {
        public abstract Rule getRule();
    }

    // 具体工厂类
    static class OddEvenRuleFactory extends RuleFactory {
        @Override
        public Rule getRule() {
            return new OddEvenRule();
        }
    }

    public static void main(String[] args) {
        int[] nums = new int[]{1, 2, 3, 4};
        System.out.println(Arrays.toString(new Solution().exchange(nums)));
    }
}
```