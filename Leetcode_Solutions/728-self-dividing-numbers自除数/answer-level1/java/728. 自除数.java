# 1. Approach 暴力求解
```java
/**
* This is a solution from LeetCode standard answer.
* @version 1.0 2019-08-12
*/
import java.util.*;

class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
        List<Integer> nums = new ArrayList();

        for(int i=left; i<=right; i++)
        {
            if(selfDivision(i))
                nums.add(i);
        }
        return nums;
    }

    public static boolean selfDivision(int number)
    {
        int quotient = number;
        while(quotient>0)
        {
            int bitValue = quotient%10;
            quotient /= 10;
            if(bitValue==0 || (number%bitValue != 0))
                return false;
        }
        return true;
    }
}
```

- 解题思路：
  - 对一个整数同时取整、取余；
  - 判断：
    - 余数是否为0；
    - 该整数是否能被余数整除；
  - 重复上述步骤，直至商（取整运算结果）为0；

