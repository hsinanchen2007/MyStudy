其实跟求素数的差不多，先说明下参数的含义
具体步骤如下：
1. 首先求num的平分根`sqrt = (int)Math.sqrt(num);`
2. 从`i = 2 .. sqrt` 查找是否存在能被num整除的数;
3. 若`num % i == 0`，进一步判断` i == num/i`，若相等，则`count ++`;否则 `count += 2, sum += (i + num/i);`
4. 再判断`count > 2`是否成立，**若成立，说明因子必定不止4个**，不满足条件，return 0; 否则进行
5. 最后判断`count == 2 ? sum : 0`;若`count`等于2，说明满足条件，返回`sum`，否则返回0；

大致就是这样，若有错误，请大佬指导。

```
class Solution {
    public int sumFourDivisors(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i : nums){
            sum += calculate(i);
        }
        return sum;
    }
    
    //num是否为四因数，若是，则返回四个数的和sum，否则返回0
    public int calculate(int num){
        int sqrt = (int)Math.sqrt(num);
        int i = 2;

        //统计出num和1外能被num整除的个数，若大于2，则返回0
        int count = 0;

        //统计所有因子的和
        int sum = 1 + num;
        while(i <= sqrt){
            //是否整除
            if(num % i == 0) {
                //判断当前值i和另外一因子num/i是否相同
                if(i != num/i){
                    count += 2;
                    sum += (i + num/i);
                }else {
                    count ++;
                }
                if(count > 2) return 0;
            }
            i ++;
        }
        return count == 2 ? sum : 0;
    }
}
```
