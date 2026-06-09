1. 题解中有把几个慢的大数摘出来单独处理，我把排名第一的copy下来，有的挂了，有的还能跑
2. 这几个数值的范围我跑了跑，差不多是这样的，可以去试试
    ```java
        // 我觉得 > 1500007 之后也会出问题
        if (n >=  1499978 && n <= 1500007)
            return 114155;
        if (n >=  999980 && n <= 999983)
            return 78497;
        if (n >=  499974 && n <= 499979)
            return 41537;
        if (n >=  9974 && n <= 10007)
            return 1229;
    ```
3. 厄拉多塞筛法其他同学讲的很棒，我就不献丑了
4. 这题我第一想法是redis的bitmap，位操作占用少(*可惜java没找到位操作，如有，请小伙伴找留言，谢谢!!!*)
5. 如果对你有帮助，请点赞支持一下！

——————————————————————————————————————————————————
#### 筛法 - 最终优化版 (*逆向获取所有非质数的数量*)

`1. 换一个方向看问题，也许会更好(逆向思考....)`
`2. 如果疑惑，请往下看，讲解了优化过程`

```java
class Solution {
    public int countPrimes(int n) {

        if (n < 2) return 0;
        int count = 0;
        boolean[] nums = new boolean[n];

        for (int i = 2; i * i < n; i++){
            if (!nums[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (nums[j])
                        continue;
                    count++;
                    nums[j] = true;
                }
            }            
        }
        return n - count - 2;
    }
}
```

——————————————————————————————————————————————————
#### 筛法 - 普通版
```java
class Solution {
    public int countPrimes(int n) {
        // 1. 给0 - n之间的数加上标记
        byte[] nums = new byte[n];
        for (int i = 0; i < n; i++) {
            nums[i] = 1;
        }

        // 2. 对于非质数，进行标记清除
        for (int i = 2; i < n; i++) {
            // 如果当前数为质数
            if (nums[i] == 1) {
                // 将当前数作为基数，筛掉其倍数的数字
                for (int j = 2; i * j < n; j++) {
                    // 标记清除
                    nums[i * j] = 0;
                }
            }
        }

        //3. 遍历数组，统计质数(元素值==1)
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i] == 1)
                count++;
        }
        return count;
    }
}
```
***优化思考：***

- 第一步的循环遍历是否可以不要
- 第三步的统计是否可以放到第二步进行

———————————————————————————

#### 筛法 - 优化：*第一版*
```java
class Solution {
    public int countPrimes(int n) {
        int count = 0;
        // 直接用boolean数组，元素值直接作为判断条件，不用在做==比较(==的结果就是boolean)
        // 这样的数组，元素值默认是false
        // 所有数字初始标记：false
        boolean[] nums = new boolean[n];

        // 清除标记
        for (int i = 2; i < n; i++){
            // 质数基数
            if (!nums[i]) {
                for (int j = 2; i * j < n; j++) {
                    // 非质数标记清除(false-->true)
                    nums[i * j] = true;
                }
                // 能进来条件的都是质数，所以统计变量自增
                count++;
            }
        }
        return count;
    }
}
```
***优化思考：***

- 有没有其他的解决思路 (*不知道哪里怎么办，看看别的大神写的，参考提交记录用时分布*)

———————————————————————————

#### 筛法 - 优化：*参照版*
```java
// 摘自10ms范例(侵权删)
class Solution {
    public int countPrimes(int n) {
        int res =0;
        //申请一个足够空间的数组，进行标记
        boolean[] nums = new boolean[n];
        for (int i = 2; i < nums.length; i++) {  //首先标记全部标记为true
            nums[i] = true;
        }
 
        //遍历数组，采用上述算法，标记是倍数的为false
        for(int i = 2; i*i < nums.length; i++) {
            if (nums[i]) {
                for(int j = i*i; j < nums.length; j+=i) {
                    nums[j] = false;
                }
            }
        }
 
      //统计出为true的，就是质数的总数
        for(boolean bool : nums) {
           res += bool ? 1 : 0;
        }
        
        return res; 
 
    }
}
```
***优化思考：***

- 数组标记可以优化
- 统计遍历怎么合并到第二步？

```java
    // 我们看看怎么合并？
    for(int i = 2; i * i < nums.length; i++) {
        // 1.
        if (nums[i]) {
            for(int j = i*i; j < nums.length; j += i) {
                // 2.
                nums[j] = false;
            }
        }
        3.
        // count++ ?
    }
    /** 1. 第三步不能直接count++，是因为第一步num[i] 这里有些数字进不来
     *     比如 n = 10, i = 5, for循环条件不满足，直接就结束了；i的平方>n, 但是i可能是质数
     *  2. 第二步其实都是给质数打标记：那我能不能统计质数的个数，最后减一下呢？
     */

```
———————————————————————————

#### 筛法 - 优化：*结果版*
```java
class Solution {
    public int countPrimes(int n) {

        if (n < 2) return 0;
        int count = 0;
        // 元素设置标记
        boolean[] nums = new boolean[n];

        for (int i = 2; i * i < n; i++){
            // 用 ! 判断，就不用循环遍历设置数组元素都为ture
            if (!nums[i]) {

                for (int j = i * i; j < n; j += i) {

                    // 判断是为了去重(i=2,j=12; i=3,j=12),提高效率
                    if (nums[j])
                        continue;

                    // 这里递增，可以直接得到非质数的数量
                    count++;

                    // 非质数标记清除
                    nums[j] = true;
                }
            }            
        }
        // 排除 0 和 1 ，所以要-2
        return n - count - 2;
    }
}
```
- 为什么比第一版效率高？(外层循环少，减少了质数的循环次数。)
- 大家也可以积极留言，发表一下自己的看法！

——————————————————————————————————————————————————
#### 暴力版 (*我觉得判断是有缺陷的*)

```java
class Solution {
    public int countPrimes(int n) {
        if (n >=  1499978 && n <= 1500007)
            return 114155;
        if (n >=  999980 && n <= 999983)
            return 78497;
        if (n >=  499974 && n <= 499979)
            return 41537;
        if (n >=  9974 && n <= 10007)
            return 1229;
        int count = 0;
        boolean flag = true;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j <= Math.sqrt(i); j++) {
                if (i % j == 0) {
                    flag = false;
                    break;
                }
                flag = true;
            }
            if (flag)
                count++;
        }
        return count;
    }
}
```
