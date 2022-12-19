# 题解
就是找出等差数列的通项公式，以及其求和公式。
## 1、模拟分配
利用取模运算直接分配。

```Java
public class Solution {
    public int[] distributeCandies(int candies,int num_people) {
        int[] res = new int[num_people];
        int count = 0;
        while (candies > 0) {
            if (candies >= count+1){
                res[count%num_people] += count+1;
            }else {
                res[count % num_people] += candies;
                break;
            }
            candies -= count+1;
        }
        return res;
    }
}
```
## 2、计算组数，至多循环两次
- 先计算可以分配的组数有多少：

candies个糖果分配给num_people个小朋友。
第i组需要的糖果数量为：
$$
    a_i = \frac{n(n+1)}{2} + (i - 1) · n^2
    = \frac{(2·i - 1)n^2 + n}{2}
$$

- 然后，将可以完全分配的组数先分配。

假如我们计算了需要分配count次，那么，最后一次算作不完全分配。我们可以对前count-1次进行统一分配，因为相邻的小朋友，固定相差count-1个糖果。

对于第一个小朋友：
第i组分配到的糖果数量为：
$$
    a_0 = 1,

    a_i = 1 + (i - 1)*n，
$$
那么第一位同学分配到第i组时，总共的糖果数量为：
$$
    S_i = (1 + 1 + (i - 1)·n)*i/2
$$
之后的，同学与前一位同学的糖果数量关系为：
$$
    s_i = s_{i - 1} + count - 1;
$$
- 处理最后一组的不完全分配。

最后一组（ 第count组 ），第一位同学应该分配的糖果数量为：
$$
    a_{count} = 1 + n(count - 1)
$$
然后，模拟分配即可。
```Java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        // 第一轮需要的所有的糖果数量
        int sum = (1+num_people)*num_people/2;
        int count = 1;
        // 统计可以分多少组
        while (candies >= sum) {
            count++;
            sum += ((2*count-1)*num_people*num_people + num_people)/2;
        }
        if (count == 1) { // 只有一组
            for (int i = 0;i < num_people;i++) {
                if (candies < i) {
                    res[i] = candies;
                    break;
                }else {
                    res[i] = i+1;
                    candies -= i+1;
                }
            }
        } else { // 存在多组
            // 计算第一位同学可以获得的 前count - 1组的糖果数量
            int first = (1 + (count-2)*num_people + 1)*(count-1)/2;
            // 推到出所有同学的糖果数量
            for (int i = 0;i < num_people;i++) {
                if (i == 0) {
                    res[i] = first;
                } else {
                    // 第i为同学的糖果数量比前一位同学的多count - 1个
                    res[i] = res[i-1] + count - 1;
                }
                candies -= res[i];
            }
            // 处理最后一行的糖果分配，因为可能分配不全。
            // 最后一组分配的
            first = 1+num_people*(count-1);
            for (int i = 0;i < num_people;i++) {
                if (candies >= first) {
                    res[i] += first;
                    candies -= first;
                    first++;
                }else {
                    res[i] += candies;
                    break;
                }
            }
        }
        return res;
    }
}
```

## 3、先一次性分配到位，再从后往前去除超额的。
直接分配糖果，不用再分情况分配了。
```java
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] res = new int[num_people];
        // 第一轮需要的所有的糖果数量
        int sum = (1+num_people)*num_people/2;
        int count = 1;
        // 统计可以分多少组
        while (candies >= sum) {
            count++;
            sum += ((2*count-1)*num_people*num_people + num_people)/2;
        }
        // 计算第一位同学可以获得的 前count - 1组的糖果数量
        int first = (1 + (count-1)*num_people + 1)*(count)/2;
        // 推到出所有同学的糖果数量
        for (int i = 0;i < num_people;i++) {
            if (i == 0) {
                res[i] = first;
            } else {
                // 第i为同学的糖果数量比前一位同学的多count - 1个
                res[i] = res[i-1] + count;
            }
            candies -= res[i];
        }
        // 说明最后一组超额分配了
        if (candies < 0) {
            int last = count*num_people;
            for (int i = num_people - 1;i >= 0;i--) {
                if (candies + last <= 0) {
                    // 多分配了last个
                    res[i] -= last;
                } else {
                    // 第一个多分配的同学，多分配了 -candies个
                    res[i] -= -candies;
                    break;
                }
                candies += last;
                last--;
            }
        }
        return res;
    }
}
```