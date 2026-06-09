## 方法一：循环规律
### 解题思路
对于while循环可以先不写break条件，然后就会发现不快乐数的循环最后会形成**4-16-37-58-145-42-20**的循环。
将这一组循环放进一个数组里，在循环中匹配计数，一旦计数达到数组长度，就说明是不快乐数，返回false即可。
这是一个取巧的方法，如果循环很大就会变得比较麻烦。

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        if (n<=0) return false;
        if (n==1) return true;
        int sum = 0;
        int[] judge = {4,16,37,58,89,145,42,20};
        int count = 0;
        while (sum!=1) {
            sum = 0;
            while (n > 0) {
                int bit = n%10;
                sum += bit*bit;
                n /= 10;
            }
            n = sum;
            if (sum==judge[count]) count++; //匹配计数
            if (count==judge.length) return false; //符合不快乐数的循环
        }
        return true;
    }
}
```

## 方法二： 快慢指针
### 解题思路
使用快慢指针的思想，慢指针每次走一步，快指针每次走两步，
每次快指针比慢指针多计算一次，累计之下快慢会相等，当快慢指针相等时，即表示循环一次。
如果快慢指针相等且等于1，那么表示是快乐数。
### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        int slow = n, fast = n;
        do{
            slow = bitSquareSum(slow);
            fast = bitSquareSum(fast);
            fast = bitSquareSum(fast);
        }while(slow != fast);

        return slow == 1;
    }

    private int bitSquareSum(int n) {
        int sum = 0;
        while(n > 0)
        {
            int bit = n % 10;
            sum += bit * bit;
            n = n / 10;
        }
        return sum;
    }
}
```

