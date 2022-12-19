这道题就是求一个长度为arr.length()的数组，每一位只能为1或者0的组合。使用回溯算法来实现，做好剪枝操作。感觉这个地方还是可以优化的。
```
class Solution {
    public int maxLength(List<String> arr) {
        int size = arr.size();
        int[] array = new int[size], ans = new int[1];
        findPermutation(array, 0, arr, ans);
        return ans[0];
    }

    public void findPermutation(int[] num, int index, List<String> arr, int[] ans) {
        if (index >= num.length) {
            if (check(num, arr, index)) {
                int max = 0;
                for (int i = 0; i < num.length; i++) {
                    if (num[i] == 1) {
                        max += arr.get(i).length();
                    }
                }
                ans[0] = ans[0] > max ? ans[0] : max;
            }
            return;
        }
        for (int i = 0; i < 2; i++) {
            num[index] = i;
            if (check(num, arr, index)) {
                findPermutation(num, index + 1, arr, ans);
            }
        }
    }

    public boolean check(int[] num, List<String> arr, int index) {
        boolean[] flags = new boolean[130];
        for (int i = 0; i < index; i++) {
            if (num[i] == 1) {
                String s = arr.get(i);
                for (int j = 0; j < s.length(); j++) {
                    if (flags[s.charAt(j)]) {
                        return false;
                    } else {
                        flags[s.charAt(j)] = true;
                    }
                }
            }
        }
        return true;
    }
}
```
