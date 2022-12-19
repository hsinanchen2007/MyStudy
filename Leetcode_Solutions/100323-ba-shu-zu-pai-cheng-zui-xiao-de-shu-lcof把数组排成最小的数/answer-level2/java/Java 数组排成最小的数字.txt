### 解题思路
解题思路见代码注释！！！

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return "";
        }

        // 核心一：将数字转换为字符串进行处理
        String[] values = new String[nums.length];
        int i = 0;
        for (int num : nums) {
            values[i++] = String.valueOf(num);
        }

        // 核心二：修改比较函数，将两个比较的字符串拼接后比较，谁在前较小则谁较小
        // 一定是拼接之后，而不是直接进行比较，例如：3，30，300数组，300303最小，而不是330300最小
        Arrays.sort(values, new Comparator<String>() {
            @Override
            public int compare(String s1, String s2) {
                String c1 = s1 + s2;
                String c2 = s2 + s1;
                return c1.compareTo(c2);
            }
        });

        String result = "";
        for (String str : values) {
            result += str;
        }

        return result;
    }
}
```