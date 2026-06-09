### 解题思路
因为时间复杂度要求为n，所以排序肯定不行，于是想到hash，把数组的全部内容存入set，随后在set中进行一次遍历，虽然set中的每一个值都有可能是那个最长的序列中的某一个。
如果对每一个元素的前一个与后一个都进行验证是否在set中没有必要，因为重复验证太多。
一个思路连续序列长度最小的肯定在set中。于是只要验证当前元素的后一个元素是否在set中(例如当前为i  只要看i-1是否在set中)
1.如果在则他不是连续序列中最小的，跳过此元素继续往后遍历
2.如果不在，则他是一个连续序列中最小的，则依次往后看i+1是否在set中并记录其长度，在与最大长度进行比较可得出最长序列。


### 代码

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums == null || nums.length < 1){return 0;}
        HashSet<Integer> set = new HashSet<Integer>();
        for(int i = 0; i < nums.length; i++){
            set.add(nums[i]);
        }

        int lengthMax = 1;
        int tempLength = 1;
        for(int number : set){
            if(set.contains(number - 1)){continue;}
            while(set.contains(number+1)){
                number++;
                tempLength++;
            }
            lengthMax = Math.max(lengthMax,tempLength);
            tempLength = 1;
        }

        return lengthMax;
    }
}
```