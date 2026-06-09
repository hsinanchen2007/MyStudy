![2020021002.PNG](https://pic.leetcode-cn.com/9a7b0cf2d06f0ca87cbce5e69f0dc8145c3f32eef6702b5667d236af8f8b4709-2020021002.PNG)

### 解题思路
//难点在于声明返回数组的大小;
//为了得到返回数组的大小,首先遍历一遍数组nums,计算索引为偶数的数字之和得到返回数组的大小len;
//声明返回数组result的大小为len;
//再遍历一遍数组,进行解码,解码原则为---索引为奇数i的数字nums[i]重复nums[i-1]次,并依次放入返回数组result中;
//最后返回out;

### 代码

```java
class Solution {
    public int[] decompressRLElist(int[] nums) {
        int i=0;
        int len=0;
        while(i<nums.length){
        	len+= nums[i];
            i+=2;
        }
        int[] result = new int[len];
        int index=0;
        i=0;
        while(i<nums.length){
            for(int k=0;k<nums[i];k++){
                result[index]=nums[i+1];
                index++;
            }
            i+=2;
        }
        return result;
    }
}
```