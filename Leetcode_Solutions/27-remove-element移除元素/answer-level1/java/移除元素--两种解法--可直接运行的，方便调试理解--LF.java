解法1：
```
package ZJM_27_移除元素;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {3, 2, 2, 3};
        int val1 = 3;

        int[] nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
        int val2 = 2;

        Solution solution = new Solution();
        int nums1l = solution.removeElement(nums1, val1);
        int nums2l = solution.removeElement(nums2, val2);

        for (int i = 0; i < nums1l; i++) {
            System.out.print(nums1[i] + " ");
        }
        System.out.println();
        for (int i = 0; i < nums2l; i++) {
            System.out.print(nums2[i] + " ");
        }
    }
}

class Solution {
    public int removeElement(int[] nums, int val) {
        int i = 0;

        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
}

/**
 * 本题与 ZJM_26_删除排序数组中的重复项类似
 * 注意一下题目要求 不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。
 * 所以类似写法，同样是定义快慢两个指针，一个用来标记与val值不同的数，用来覆盖原数组，
 * 一个当遇到nums数组中与val值相等的元素时，跳过此元素，直到遇到与val值不相等的元素在将其赋值到前面覆盖
 * 最终遍历得到的就是符合要求的数组，此处因为不用保留一个重复的元素，所以后++，先赋值，数组长度就是i的值
 */

```
解法2：
```
package ZJM_27_移除元素;

public class Main2 {
    public static void main(String[] args) {
    String haystack1 = "hello", needle1 = "ll";
    String haystack2 = "aaaaa", needle2 = "bba";
    String haystack3 = "aa", needle3 = "";
    String haystack4 = "aaa", needle4 = "aa";
    String haystack5 = "aaabb", needle5 = "baba";
    String haystack6 = "a", needle6 = "a";
    String haystack7 = "mississippi", needle7 = "issip";

    Solution2 solution = new Solution2();
    System.out.println(solution.strStr(haystack1,needle1));     //2
    System.out.println(solution.strStr(haystack2,needle2));     //-1
    System.out.println(solution.strStr(haystack3,needle3));     //0
    System.out.println(solution.strStr(haystack4,needle4));     //0
    System.out.println(solution.strStr(haystack5,needle5));     //-1
    System.out.println(solution.strStr(haystack6,needle6));     //0
    System.out.println(solution.strStr(haystack7,needle7));     //4
}
}

class Solution2 {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}

/**
 * 调用函数写法，直接使用字符串indexOf函数得到结果
 * indexOf() 方法可返回某个指定的字符串值在字符串中首次出现的位置。
 */

```
