### 解题思路
1.当k为零，直接提交空就可以。
2.遍历一次数组，找到最大值。
3.定义一个容量为最大值+1（最差10001个）的数组，对应下标元素统计与下标相同的值的个数
4.从小到大，找齐需要的k个
### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        //0个
        if(k == 0){
            return new int[0];
        }
        //最大值坐标
        int t = 0;
        for(int i=0; i<arr.length; ++i){
            if(arr[i] > arr[t]){
                t = i;
            }
        }
        //长度为最大值+1的数组
        final int MAX = arr[t]+1;
        int[] nums = new int[MAX];
        //记录个数
        for(int i=0; i<arr.length; ++i)
        {
            ++nums[arr[i]];
        }
        //定义提交数组
        final int K = k;
        int[] Arr = new int[K];
        //写入
        int j=0;
        for(int i=0; i<MAX+1; ++i){
            while(nums[i] > 0){
                Arr[j] = i;
                ++j;
                --nums[i];
                if(j >= K){
                    return Arr;
                }
            }
        } 
        return Arr;
    }
}
```