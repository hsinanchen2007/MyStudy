### 解题思路
重写Comparater，对String数组排序，最后按顺序添加到字符串中即可。

### 代码

```java
class Solution {
    public String minNumber(int[] nums) {
        int numsLen = nums.length;
        String[] strNum = new String[numsLen];
        for (int i = 0; i < numsLen; i ++) {
            strNum[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(strNum, new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                if ((a + b).compareTo(b + a) < 0)
                    return -1;
                return 1;
            }
        });
        StringBuilder ans = new StringBuilder();
        for (String str : strNum)
            ans.append(str);
        return ans.toString();
    }
}
```