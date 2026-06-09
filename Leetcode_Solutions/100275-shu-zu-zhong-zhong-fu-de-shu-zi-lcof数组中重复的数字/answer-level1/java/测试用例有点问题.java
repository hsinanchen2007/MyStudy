### 解题思路
感觉测试用例有问题，如果numsnums[]里有数字大于numsnums.length的话应该通不过才对。然而过了。
![QQ截图20200214191945.png](https://pic.leetcode-cn.com/941c3895631782bbfcd15f1d2c5c71108730b792435e78ba24ac2b132b36ad72-QQ%E6%88%AA%E5%9B%BE20200214191945.png)


### 代码

```java
class Solution {
    public int findRepeatNumber(int[] nums) {
        if(nums.length==0)return -1;

        int len=nums.length;
        int[] counter=new int[len];

        for(int i:nums){
            counter[i]++;
            if(counter[i]>=2)return i;
        }
        return -1;
    }
}
```