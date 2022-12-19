思路：
逐个从nums数组中取出
再将其和nums中所有元素比较（注意：比较结束需将count重置为0）
小于的话count++
将count存入新数组（这里要注意count存入时要和nums中取出的数的索引位置相同=。=）

时间复杂度`O(n^2)` 
枚举nums `O(n)`  和nums中所有数据依次比较`O(n)`

就酱（逃.

```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        //new一个新数组
        int[] newArr = new int[nums.length];
        int c = 0;
        //每次取出一个进行遍历
        for(int num : nums){
            //count重置
            int temp = num, count = 0;
            for(int i = 0; i < nums.length; i++){
                //数组中元素小于当前数，count++
                if(nums[i] < temp){
                    count++;
                }
            }
            //有效j（小于的个数）放入数组中
            newArr[c] = count;
            c++;
        }
        return newArr;
    }
}
```
