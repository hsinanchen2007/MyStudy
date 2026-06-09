从题目描述，可看出以下几点：

正确的数组，排序后其元素应该是：1，2，3 ... n（当然，此题我们不需要排序）
错误的数组，排序后其元素应该是：1，2，3 ... m，m, ... n

此时，就出现了三种情况，重复的元素，出现了 2 次，正确的元素出现了 1 次，丢失的元素出现了 0 次。

于是，很自然的可以想到，用一个数组进行存储其出现的次数。

定义一个元素出现次数的数组：
      int count[] = new int[10002];

其中，count数组下标为错误的数组nums的元素值
通过遍历数组nums，利用
      count[nums[i]]++;
来计算每一个元素出现的次数，次数存储在count中

最后，遍历count数组，其值为 0 的便是丢失的数组，其值为 2 的便是重复的数组
```
public int[] findErrorNums(int[] nums) {

        int out[] = new int[2];

        //1。方法一：
        int count[] = new int[10002];
        for(int i = 0; i < nums.length; i++){
            count[nums[i]]++;

        }

        for(int i = 0; i <= nums.length; i++){
            if(count[i] == 2)
                out[0] = i;
            if(count[i] == 0 && i != 0 && i <= nums.length)
                out[1] = i;
        }

        return out;

    }