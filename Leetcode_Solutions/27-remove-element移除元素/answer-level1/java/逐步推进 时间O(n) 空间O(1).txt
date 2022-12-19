### 解题思路
题解看代码

![image.png](https://pic.leetcode-cn.com/3a67fe86bb3d02f6997e7f68e659961365590bbf17c94b430642ff29e3af30a6-image.png)


### 代码

```java
class Solution {
    public int removeElement(int[] nums, int val) {
       //包含指定数的位置，默认是不包含指定数，所以需要替换的位置为-1
        int pos = -1;
        //计数
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                count++;
                if (pos != -1) {
                    //赋值到新的位置
                    nums[pos] = nums[i];
                    //向后推进一步
                    pos++;
                }
            }
            //只需要找到一个为指定数即可，后面的把位置向前推进一步就可以
            if (nums[i] == val && pos == -1) {
                pos = i;
            }
        }
        return count;
    }
}
```