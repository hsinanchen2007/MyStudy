* 1. 想着如果要在常数内存中解决问题，就只能命名单个变量或者直接使用原来的nums。所以就想到了直接在原来的nums上面标记。
 * 2. 时间上是n，那么不能排序。
 * 2. 方法就是直接根据数组的值作为下标标记对应的位置。首先，如果数组中有大于数组下标的值，那么整个数组就一定有某个地方少了某些数。
 * 因为数字的个数和数字的字面大小长度是对应起来的。
 * 3. 不过并不容易，因为细节问题还是要考虑。比如使用0标记存在的数字，那么原来就是0的要先排除; 如果是连续的从1开始的，那么结果应该是length+1，而不是length。
 * 4. 时间：1ms,击败99.51%，内存34.4MB，击败90.47
 * 5. temp在for循环里面生命消耗的内存更少。按道理，二者没啥差别？
 * 6. lastNum使用boolean还不如使用int消耗内存少，为啥？
 * 7. 看了官方题解，思路和自己的一样。需要遍历三次数组。不过自己没能达到100%

```
public int firstMissingPositive(int[] nums) {
        boolean lastNum = false;
        if (nums.length == 0)
            return 1;

        // 肯定不会超过nums的长度
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        for (int i = 0; i < nums.length; i++) {

            if (nums[i] <= 0) {
                continue;
            }

            int temp = nums[i];

            while (temp < nums.length && temp > 0) {
                int temp2 = nums[temp];
                nums[temp] = 0;
                temp = temp2;
            }
            if (temp == nums.length) {
                lastNum = true;
            }

        }
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != 0) {
                return i;
            }
        }
        return lastNum ? nums.length + 1 : nums.length;

    }
```
