![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/053812e365fa6af99bac2d0012be9cc4d24e686cd4198fbf3895e40a67c508d9-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()==0) return 0;
        char[] arr = s.toCharArray();
        int len = 1;
        int begin = 0;
        int res = 1;
        boolean flag = false;
        for (int i = 1; i < arr.length; i++) {
            //对于每一个i，我们需要得到len和begin的序号数字。
            for (int k = i - 1; k >= begin; k--) {
                if (arr[k] == arr[i]) {
                    begin = k +1;
                    break;
                }
            }
            len = i - begin + 1;
            if (len > res) res = len;
            flag = false;
        }
        return res;
    }
}

```