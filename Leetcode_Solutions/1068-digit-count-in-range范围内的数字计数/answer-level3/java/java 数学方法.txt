### 解题思路
类似233的思路做。
![111.png](https://pic.leetcode-cn.com/7284f4d56abc34cd203d93d7bdd3be0243b784c06ca7468771f9eca134090412-111.png)


### 代码

```java
class Solution {
    public int digitsCount(int d, int low, int high) {
        //(0,high] - (0, low-1]
        return count(d, high) - count(d, low-1);
    }

    private int count(int d, int n) {
        //low-1可能小于0
        if(n < 0) return 0;
        //d=0场景比较特殊，以下不会到for循环，这里直接返回
        if(n == 0 && d == 0) return 1;
        int ans = 0;
        for(int i=1; i<=n; i*=10) {
            int divider = i*10;
            //d=0时，特殊情况，十位及其高位都不会以0开始，需要减去一个i
            //d=0的个位还是符合常规，可以个位单独为0
            if(i >= 10 && d == 0) {
                ans += (n/divider-1)*i; 
            } else {
                ans += (n/divider)*i;
            }
            //考虑低位，d=3的十位，如果后两位数temp，小于30，则十位不会出现3
            //如果temp<=39，则十位出现3的个数为temp-30+1;
            //如果temp>=40, 则十位出现3的个数为10
            int temp = n%divider;
            if(temp < d*i) {
                continue;
            } else if(temp < (d+1)*i) {
                ans += temp-d*i + 1;
            } else {
                ans += i;
            }
        }
        return ans;
    }
}
```