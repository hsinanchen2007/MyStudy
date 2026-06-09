### 解题思路
没看好题，把所有可能的情况也打印了，也算是一种思路吧（万一有题目要得到所有结果呢）。用before记录上一个数字传递的值
每道题一写半小时，代码忒臃肿，和大佬们水平差太多

### 代码

```java
class Solution {
   Set<String> result;
    public int translateNum(int num) {
        result = new HashSet<>(); //使用HashSet去掉重复结果。
        List<Integer> list = new ArrayList<>();
        if (num == 0) {
            list.add(0);
        }
        while (num / 10 + num % 10 != 0) {
            list.add(num % 10);
            num /= 10;
        }
        int[] nums = new int[list.size()];
        for (int i = 0; i < list.size(); i++) {
            nums[i] = list.get(list.size() - i - 1); //将数字转换为数组。
        }

        dfs(nums, 0, 0, "");
        System.out.println(result);

        return result.size();
    }

    public void dfs(int[] nums, int len, int before, String str) {
        if (len >= nums.length) {
            if (before == 0) {
                result.add(str);
                return;
            } else {
                result.add(str + numToChar(before));
                return;
            }
        }

        if (before == 0) {
            if (nums[len] >= 3 || nums[len] == 0) {
                dfs(nums, len + 1, 0, str + numToChar(nums[len]));
            }

            if (nums[len] == 1) {
                dfs(nums, len + 1, 1, str); //before置为1，等待与下一位结合。
                dfs(nums, len + 1, 0, str + numToChar(nums[len])); //直接转为字母。
            }
            if (nums[len] == 2) {
                dfs(nums, len + 1, 2, str);
                dfs(nums, len + 1, 0, str + numToChar(nums[len]));
            }
        } else if (before == 1) {
            dfs(nums, len + 1, 0, str + numToChar(before * 10 + nums[len]));

        } else if (before == 2) {
            if (nums[len] > 5) {
                dfs(nums, len + 1, 0, str + numToChar(before) + numToChar(nums[len]));
            }
            if (nums[len] <= 5) {
                dfs(nums, len + 1, 0, str + numToChar(before * 10 + nums[len]));
            }
        }
    }
	
    public char numToChar(int num) { //数字转换为字母。
        return (char) (num + 'a');
    }


}
```