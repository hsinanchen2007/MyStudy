我的想法很简单
1.既然能分成三份，那整个数组的和肯定能被3整除
2.数组的和除3得到均分后的结果子和subsum
3.再次遍历数组，通过求能达到subsum这个值的次数count
4.如果count>=3 则是正确的能三等分的数组(count大于3的随便怎么分都行，都能分成三等分)
代码如下:
```c++
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int i = 0;i < A.size();i++)
        {
            sum += A[i];

        }
        if (sum % 3 != 0)
            return false;
        int subSum = sum / 3;
        int count = 0;
        int temp = 0;
        for (int i = 0; i < A.size(); i++)
        {
            temp += A[i];
            if (temp == subSum)
            {
                temp = 0;
                
                count++;
            }
        }
        return count >= 3;
    }
};
```
