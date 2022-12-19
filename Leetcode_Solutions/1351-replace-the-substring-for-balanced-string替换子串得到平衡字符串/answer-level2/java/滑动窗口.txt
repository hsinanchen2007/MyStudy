```java
class Solution {
    public int balancedString(String s) {
        // count 的作用：
        // 1. 首先用于统计整个字符串中所有字符的个数
        // 2. 然后用于维护滑动窗口外的字符的个数
        int[] count = new int[128];
        char[] arr = s.toCharArray();

        for (char c : arr) {
            count[c]++;
        }

        int need = s.length() / 4;

        // 滑动窗口
        int left = 0;
        int right = 0;
        int min = arr.length;
        while (right <= arr.length) {
            // 如果 count 中的字符的个数有一个大于 need 的话，则移动 right
            // 扩大窗口，减去 count 中相应字符出现的次数
            if (count['Q'] > need || count['W'] > need 
                    || count['E'] > need || count['R'] > need) {
                if (right >= arr.length) break;
                char rightCh = arr[right];
                // 滑动窗口内的字符的个数减一
                count[rightCh]--;
                right++;
                continue;
            }

            // 缩小窗口，加上 count 中相应字符出现的次数
            // 这个时候 count 中的字符的个数都 小于等于 need
            // 开始移动 left，并且将 left 对应的字符的个数加一
            min = Math.min(min, right - left);
            if (min == 0) break;
            char leftCh = arr[left];
            count[leftCh]++;
            left++;
        }

        return min;
    }
}
```