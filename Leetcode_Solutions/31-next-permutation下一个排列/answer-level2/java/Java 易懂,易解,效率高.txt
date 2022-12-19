**1.本题是在了解官方解题的基础上自己写出来的代码,具体数学计算过程可以参考官方题解,如果官方题解代码有疑惑,可以参考本人所叙述写代码的方法,仅供参考;
2.本质上这种题有两种情况:
(1):如果是降序数组,则下一个排列数字为最小数字,即将数组全部反转即可;
(2):一般情况,首先定义两个index1和index2指针用于保存左右要交换的数字,首先从后往前遍历,得到第一次的nums[i - 1] < nums[i],将下标保存分别赋值index1=i-1,index2=i,(如果遍历完后index还是等于-1,即数组为降序数组,直接反转数组即可),而index2不一定是当前下标,需要从i=index2到数组末尾继续遍历,如果nums[i] > nums[index1]就继续遍历赋值,最后反转index1 + 1到数组末尾的数字即可得到下一个排列;
3.完结。**


        public void nextPermutation(int[] nums) {
            int index1 = -1, index2 = -1;
            for (int i = nums.length - 1; i > 0; i--) {
                if (nums[i] > nums[i - 1]) {
                    index1 = i - 1;
                    index2 = i;
                    break;
                }
            }
            if (index1 == -1) {
                int start = 0, end = nums.length - 1;
                while (start < end) {
                    int temp = nums[start];
                    nums[start++] = nums[end];
                    nums[end--] = temp;
                }
                return;
            }
            for (int i = index2; i < nums.length; i++) {
                if (nums[i] > nums[index1])
                    index2 = i;
            }
            int temp = nums[index1];
            nums[index1] = nums[index2];
            nums[index2] = temp;
            int start = index1 + 1, end = nums.length - 1;
            while (start < end) {
                int tem = nums[start];
                nums[start++] = nums[end];
                nums[end--] = tem;
            }
        }