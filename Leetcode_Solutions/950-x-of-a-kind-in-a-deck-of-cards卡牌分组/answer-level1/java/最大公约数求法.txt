### 解题思路
思路很简单，根据题意我们可以先将所有的数组中数字出现的频率找出来，这里我先想到的是使用HashMap，但是由于给出了数组的元素个数范围，于是可以直接利用一个数组来统计每个数字出现的频率，其大小定义为数组中数字的范围的上限。得到所有的数字出现频率之后，我使用了辗转相除法(gcd算法)，遍历求出的频率数组，注意这里只需要遍历一次这个数组而不需要两两比较，比如，x和y的最大公约数是m(m > 1)，而计算z和x以及y三者的最大公约数的时候只需要计算m和z的最大公约数，当遍历过程中出现最大公约数为1的时候直接返回false，而当遍历到的数字出现频率为0的时候直接continue。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] nums){
        if (nums == null || nums.length < 2){
            return false;
        }
        int[] base = new int[1001];
        for (int num : nums){
            base[num] += 1;
        }

        int curGcd = base[nums[0]];
        for (int b : base){
            if (b == 1){
                return false;
            }else if (b == 0){
                continue;
            }else{
                curGcd = getGcd(curGcd, b);
                if (curGcd == 1){
                    return false;
                }
            }
        }
        return true;
    }


    private int getGcd(int x, int y){
        if (x % y != 0){
            return getGcd(y, x % y);
        }
        return y;
    }
}
```