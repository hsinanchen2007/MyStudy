### 解析
本题其实是一个很典型的双指针题。如果数组的长度小于2，直接返回数组的长度即可。
 我们在遍历过程中只需要指定两个变量，一个是遍历到了哪个位置ahead，另一个是最后存放最后无重复数组的最后的位置cur。
 当nums[ahead] != nums[cur]时表示nums[ahead]是可以加进最后无重复数组的，反之，则不能加入。
 最后返回的数组的长度即为cur+1
  对于nums={1,2,2,3,3,3},其过程如下图所示。
  
![WeChat2baf300b0614e6439ef2bb0e2c372d69.png](https://pic.leetcode-cn.com/91a3500a40889dea5bdeea778dd0d5efb448b801b2192f41426d72d65bd821e5-WeChat2baf300b0614e6439ef2bb0e2c372d69.png)
###   代码
```java
public static int removeDuplicates(int[] nums) {
        assert nums != null;
        if(nums.length < 2){
            return nums.length;
        }
        int cur = 0;
        int ahead = 1;
        while(ahead < nums.length){
            if(nums[ahead] != nums[cur]){
                nums[++cur] = nums[ahead];
            }
            ahead ++;
        }
        return cur+1;

    }
```
本人建了个公众号用于刷题交流，欢迎关注：
![qrcode_for_gh_8eedbc428c9a_258(1).jpg](https://pic.leetcode-cn.com/e5f794b173fbe256a541447fc7ff8e6eb031774890bdfdb48ca3c7866dc81dc2-qrcode_for_gh_8eedbc428c9a_258\(1\).jpg)
