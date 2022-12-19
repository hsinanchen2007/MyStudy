### 解题思路
解题思路见代码

### 代码

```java
import java.util.Arrays;
import java.util.Comparator;

/**
 * 直接进行一个排序，只不过定义好比较器
  */

class Solution {
    public String largestNumber(int[] nums) {
        String[] strArr = new String[nums.length];
        for(int i=0; i<nums.length; i++){
            strArr[i] = nums[i] + "";
        }

        Arrays.sort(strArr, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                // 定义好优先级
                return (o2 + o1).compareTo(o1+o2);
            }
        });

        StringBuilder res = new StringBuilder();
        for(int i=0; i<strArr.length; i++){
            res.append(strArr[i]);
        }

        String ret = res.toString();
        // 找到第一个不为0的数字
        for(int i=0; i<ret.length(); i++){
            if(ret.charAt(i) != '0'){
                return ret.substring(i, ret.length());
            }
        }

        return "0";
    }
}
```