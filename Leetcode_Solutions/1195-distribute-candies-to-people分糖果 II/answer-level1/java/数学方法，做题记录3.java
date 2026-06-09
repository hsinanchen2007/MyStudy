![TIM图片20200305120230.png](https://pic.leetcode-cn.com/58696dccf5a7c174a9031b9cc163ea0f302756e581772502fcbc2cea9bf48d25-TIM%E5%9B%BE%E7%89%8720200305120230.png)

#### 方法一：暴力，模拟发糖

##### 思路

直接模拟发糖的过程，第一个发`1`个、第二个发`2`个\.\.\.当计数变量超过`num_people`时，通过取余运算模拟发糖过程。代码如下：

```java []
class Solution {
    public static int[] distributeCandies(int candies, int num_people) {
        int count = 1;
        int cur = 0;
        
        int[] ans = new int[num_people];
        while (candies > 0) {
	    if (cur >= num_people)
	        cur %= num_people;
	    if (count > candies) {
	        ans[cur] += candies;
	        break;
	    }
	    candies -= count;
	    ans[cur++] += count++;
	}

	return ans;
    }
}
```

##### 复杂度分析
+ 时间复杂度：$O\left(\max(\sqrt{C},\space N)\right)$ <br> 其中$C$为糖果数，$N$为人数
+ 空间复杂度：$O\left( N \right)$ <br> 需要开辟一个大小为$N$的数组储存结果


#### 方法二：等差数列

##### 思路

分析题目，发糖的方式是逐渐递增。如果确定了`candies`和`num_people`的值，其实就可以求出每个“小朋友”分到多少糖。这里我们假设一共进行了$count$次分糖。由于分糖的结果呈等差数列，所以$count$次分糖的一共分出去了$\frac{(1+count) \times count}{2}$个糖果。所以，通过解方程

$$(count + \frac{1}{4})^2 = 2\times candies$$

可以计算出$count$的近似值。同时，由于结果是等差数列，公差为$times$，即发糖的轮次。只需要计算出首项是多少就可以确定每个小朋友得到的糖果数量。根据题意，首项为:

$$ ans_0 = \frac{times \times(times - 1) \times num\_people}{2} + times$$

```java []
class Solution {
    public int[] distributeCandies(int candies, int num_people) {
        int[] ans = new int[num_people];

        int count = (int) (Math.sqrt((candies << 1) + 0.25) - 0.5);
        int times = count / num_people;
        int mod = count % num_people;
        if (count >= num_people) {
            ans[0] = (times * (times - 1) * num_people >> 1) + times;
            for (int i = 1; i < num_people; i++)
                ans[i] = ans[i - 1] + times;
        }

        for (int j = 0; j < mod; j++) 
            ans[j] += count - mod + j + 1;
        ans[mod] += candies - ((count + 1) * count >> 1);

        return ans;
    }
}
```

##### 复杂度分析

+ 时间复杂度：$O\left( N \right)$ <br> 只需要遍历一遍数组
+ 空间复杂度：$O\left( N \right)$ <br> 需要开辟一个大小为$N$的数组储存结果