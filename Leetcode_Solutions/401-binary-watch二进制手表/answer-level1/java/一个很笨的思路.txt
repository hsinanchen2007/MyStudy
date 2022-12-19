### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    
    // 小时的位数
    int n = 4;
    // 分钟的位数
    int m = 6;
    // 存储二进制
    int[] nums = new int[n + m];
    
    // num表示nums被设置为1的个数
    public List<String> readBinaryWatch(int num) {
        
        List<String> result = new ArrayList<>();
        readBinaryWatch(0, num, result);
        return result;
    }
    
    private void readBinaryWatch(int start, int num, List<String> result) {
        
        if (num <= 0) {
            String str = toString(n);
            if (str != null) {
                result.add(str);
            }
            return;
        }
        
        for (int i = start; i < nums.length - num + 1; i++) {
            nums[i] = 1;
            readBinaryWatch(i+1, num-1, result);
            nums[i] = 0;
        }
    }
    
    // 转化为时间
    private String toString(int n) {
        
        int hour = 0, minute = 0;
        
        int i = 0;
        while (i < n) {
            hour = hour * 2 + nums[i++];
        }
        
        if (hour > 11) {
            return null;
        }
        
        while (i < nums.length) {
            minute = minute * 2 + nums[i++];
        }
        
        if (minute > 59) {
            return null;
        }
        
        return "" + hour + ":" + (minute < 10 ? "0" + minute : minute);
    }
}
```