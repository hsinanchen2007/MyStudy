### 思路
思路很简单，其实就是计算一共有多少种糖果，假设为`x`，如果`x >= n / 2`，那么妹妹能分到的最大糖果种类数就是`n / 2`，否则，妹妹能分到的最大糖果种类数就是`x`。因此呢我们的目标就是求的这个`x`。还有，如果我们在计算过程中发现`x >= n / 2`, 就可以无需再往下计算了。因此，大致有以下几种方法：
- 用一个`HashSet`来存放所有的糖果，`HashSet`的`size`就是所要求的`x`；
- 先对数组进行排序，排完序的数组，相同的肯定是挨在一起的，如`1,1,2,2,2,3`。因此如果碰到`candies[i] != candies[i - 1]`,则糖果种类数即可+1，直到种类数 `== n / 2`为止；
- 已知数组中数字的范围`[-100,000, 100,000]`，因此我们可以先将数组都加上最小的值的相反数`100,000`，让所有的数都`>=0`,然后开辟一个`boolean[]`，用于记录前面的数字是否已出现过，如果没出现过的话，糖果种类数+1，同方法二，直到种类数 `== n / 2`为止；
<br>
### 方法1 HashSet
```java
    public int distributeCandies(int[] candies) {
        Set<Integer> set = new HashSet<>();
        for (int num : candies) {
            set.add(num);
        }
        return Math.min(candies.length / 2, set.size());
    }
```

#### 复杂度分析
- 时间复杂度：$O(n)$。然而由于使用到了`HashSet`，因此时间复杂度虽然是$O(n)$，但是有一个较大的常数
- 空间复杂度：$O(n)$。

### 方法2 排序
```java
    public int distributeCandies(int[] candies) {
        Arrays.sort(candies);
        int len = candies.length;
        int ans = 1;
        if (len == 2) {
            return ans;
        }

        for (int i = 1; i < len; i++) {
            if (candies[i] != candies[i - 1]) {
                ans++;
                if (ans == len / 2) {
                    return ans;
                }
            }
        }

        return ans;
    }
```
#### 复杂度分析
- 时间复杂度：$O(nlogn)$。因为使用到了`sort`
- 空间复杂度：$O(1)$。

### 方法3 标记数组
```java
    public int distributeCandies(int[] candies) {
        int half = candies.length >>> 1;
        int ans = 0;
        boolean[] visited = new boolean[200001];
        for (int candy : candies) {
            candy += 100000;
            if (!visited[candy]) {
                ans++;
                if (ans == half) {
                    return ans;
                }
            }
            visited[candy] = true;
        }

        return ans;
    }
```
#### 复杂度分析
- 时间复杂度：$O(n)$。
- 空间复杂度：$O(n)$。
说明：虽然这个方法的时间复杂度和空间复杂度都与方法1(`HashSet`)的一样，但是由于`HashSet`有一个较大的常数，因此该方法的实际执行时间会更少。
