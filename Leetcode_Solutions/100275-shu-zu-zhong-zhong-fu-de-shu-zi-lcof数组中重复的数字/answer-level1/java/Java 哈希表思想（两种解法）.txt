解法一：
简单粗暴 直接使用HashSet快速搞定

```
public class Solution {
    public int findRepeatNumber(int[] nums) {

        HashSet<Integer> set = new HashSet<>();
        for(int i = 0; i < nums.length; i ++){
            if(!set.add(nums[i])){
                return nums[i];
            }

        }
        return -1;
        }
}
```

解法二：深刻理解哈希表hashcode方法
因为题目的数值范围是0-99999，我们可以很好的使用自己定义的hashcode方法，用一个数组实现Hashset
所以，我们可以定义一个数组res[]，总容量为100000。数组中存放的元素是对应数字出现的频率。例如，原题输入[2, 3, 1, 0, 2, 5, 3]，
res[] = {1,1,2,2,0,0,1,0,0,0.....};
然后遍历该数组，找到元素出现频率大于2的第一个元素，将该元素输出

```
public class Solution {
    public int findRepeatNumber(int[] nums) {

        int[] res = new int[100000];

        for(int i = 0; i < nums.length; i ++){
            res[nums[i]] ++;
        }

        for(int i = 0; i < nums.length; i ++){
            if(res[nums[i]] >= 2)
                return nums[i];
        }
        return -1;

    }
}
```