### 分析
用两个变量ahead和cur分别代表待存入的位置和已经到达的位置。
如果nums[ahead] != val，那么进行赋值操作。nums[cur] = nums[ahead]，赋值完ahead和cur均右移一位。
否则仅将ahead右移一位。
### 代码
```java
public int removeElement(int[] nums, int val) {
        int cur = 0;
        int ahead = 0;
        while(ahead < nums.length){
            if(nums[ahead] != val){
                nums[cur++] = nums[ahead];
            }
            ahead++;
        }
        return cur;
    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)