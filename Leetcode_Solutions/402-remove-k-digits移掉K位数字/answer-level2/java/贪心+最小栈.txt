从nums中删除k个字符求最小数字等价于从nums中选nums.length-k个数字求最小数字；
例子：
对于num="1432219",k=3,等价于从"1432219"取4位数字，使得结果最小；
1. 贪心选取：要使得最终数字最小，我们只要从高到低在可选范围内使得每一位最小，最终数字肯定是最小；
2. 可选范围：因为数字是高位到低位的顺序取，所以取完的数字不能重复选取，而且前面的数字也不能再取了。
设结果为S，即：
如果我们已经取了nums[i]作为结果集的第S[j]数字，那么第S[j+1]只能从nums(i+1) ~ num(nums.length-k+(j+1))取,因为nums剩下的可选数字长度必须大于等于S剩下的数字长度，否则不够选；

这里我们实现了一个存取复杂度均为O(1)的最小栈，用来取nums(i+1) ~ num(nums.length-k+(j+1))范围的最小值，由于存在重复的最小值情况，因此我们选到了最小值之后，从左至右遍历nums选择第一个符合条件的最小值的index，作为下一个数字选取的左边界(不包含）；
```
public class Solution {
    /* 最小栈的实现 */
    class MinQue {
        ArrayDeque<Integer> mNumsQue;
        ArrayDeque<Integer> mMinQue;
        int[] nums;

        public MinQue(int[] nums) {
            this.nums = nums;
            mNumsQue = new ArrayDeque<>();
            mMinQue = new ArrayDeque<>();
        }

        public void pushBack(int index) {
            pushBackInner(mNumsQue, mMinQue, index);
        }

        private void pushBackInner(ArrayDeque<Integer> numQue, ArrayDeque<Integer> minQue, int index) {
            numQue.add(index);
            if (minQue.isEmpty()) {
                minQue.add(index);
            } else {
                int minIndex = minQue.peekLast();
                minQue.add(nums[minIndex] >= nums[index] ? index : minIndex);
            }
        }

        public int pop() {
            int numIndex = mNumsQue.pop();
            int minIndex = mMinQue.pop();
            if (!mMinQue.isEmpty() && mMinQue.peekLast() == minIndex) {
                ArrayDeque<Integer> newNumsQue = new ArrayDeque<>();
                ArrayDeque<Integer> newMinQue = new ArrayDeque<>();
                while (!mNumsQue.isEmpty() && !mMinQue.isEmpty()) {
                    pushBackInner(newNumsQue, newMinQue, mNumsQue.pop());
                    mMinQue.pop();
                }
                mNumsQue = newNumsQue;
                mMinQue = newMinQue;
            }
            return nums[numIndex];
        }

        public boolean isEmpty() {
            return mMinQue.isEmpty() || mNumsQue.isEmpty();
        }

        public int min() {
            if (!mMinQue.isEmpty()) {
                return nums[mMinQue.peekLast()];
            }
            return 0;
        }
    }
    public String removeKdigits(String num, int k) {
        if (num == null || num.length() == 0) {
            return "";
        }
        if (num.length() <= k) {
            return "0";
        }
        char[] chars = num.toCharArray();
        int[] nums = new int[chars.length];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = chars[i] - '0';
        }
        int leftLen = nums.length - k;
        MinQue minQue = new MinQue(nums);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i <= k; i++) {
            minQue.pushBack(i);
        }
        int start = 0;
        int end = k;
        int min = minQue.min();
        sb.append(min);
        while (sb.length() < leftLen) {
            /* 找到左边界第一个等于min的index */
            do {
                start++;
            } while (minQue.pop() != min);
            end++;
            /* 右边界向右挪一位 */
            minQue.pushBack(end);
            /* 求新的最小值 */
            min = minQue.min();
            sb.append(min);
        }
        int i = 0;
        /* 去除前缀多余的0 */
        while (i < sb.length() && sb.charAt(i) == '0') {
            i++;
        }
        if (i == sb.length()) {
            return "0";
        }
        return sb.substring(i, sb.length());
    }
}

```

