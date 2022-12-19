最先想到的就是桶排序,但是看了排名第一的精选题解后,
觉得哈希表法也是很不错的方法,但是效率略低于桶排序.
先排序再遍历方法通常效率不够,
但是使用quadsort算法(https://github.com/scandum/quadsort/blob/master/quadsort.c)
能够达到O(n)的时间复杂度,可以一试.

  /*
     * 方法1 桶排序
     * 使用空间换时间的策略，
     * 将nums[i]存储在数组vec的第i位置，
     * 当多次出现时，数组i位置的数vec[i]++，
     * 最后遍历存储数组vec，返回vec[i]>1的下标i
     * 时间复杂度O(n)，空间复杂度O(max(nums))
     * */

```
int findRepeatNumber(std::vector<int> &nums) {
    int n = 0;

    int i;
    // 找到数组中最大的数，
    // 该步骤可省略，可将存储数组的大小设置为最大值
    for(i = 0; i < nums.size(); i++){
        if(n < nums[i]){
            n = nums[i];
        }
    }

    std::vector<int> numcount(n+1);

    for(i = 0; i < nums.size(); i++){
        numcount[nums[i]]++;

        if(numcount[nums[i]] > 1) {
            return nums[i];
        }
    }

    return 0;
}
```

    /*
     * 方法2 哈希表
     * 先使用C++中的unorder_map建立哈希表,
     * 使用循环将数据插入到哈希表中,
     * nums[i]是key,i是value,
     * 当同一个key对应的value > 1时,
     * 则返回该key
     * 时间复杂度O(n),空间复杂度O(n)
     * */

```
int findRepeatNumber2(std::vector<int> &nums) {
    std::unordered_map<int, int> hash(nums.size());

    for(int& num : nums){
        hash[num]++;

        if(hash[num] > 1){
            return num;
        }
    }

    return 0;
}
```


    /*
     * 方法3 排序法
     * 使用通用排序算法将数据排序好后再遍历
     * 但通用排序算法的时间复杂度最快也只能达到O(nlogn)<快速排序,归并排序和堆排序>
     * 所以使用基于归并排序的最新设计的quadsort排序方法
     * 该方法源于github : https://github.com/scandum/quadsort/blob/master/quadsort.c
     * 排序时间复杂度可达到O(n)
     * */

```
int findRepeatNumber3(std::vector<int>& nums) {

    // using quadsort algorithm ==> sort time only O(n) 
    // convert std::vector<int> to int *
    // just use std::vector function data()
    quadsort(nums.data(), nums.size(), sizeof(int), cmp_int);

    int c = nums[0];
    for(int i = 1; i < nums.size(); i++){
        if(c == nums[i]){
            return c;
        } else {
            c = nums[i];
        }
    }

    return 0;
}
```

