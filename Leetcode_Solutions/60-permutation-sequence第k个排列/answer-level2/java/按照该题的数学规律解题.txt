### 解题思路

输入: n = 4, k = 9
输出: "2314"

推算出2314的过程如下:
input: n = 4, k = 9;
假如我们把所有排列列举出来，n=4的时候会有24个排列，我们要找出第9个排列是什么？
那么4的阶乘recursion = 24,24个排列划分为4个区间，每个区间长度divide = 6，可选数组[1,2,3,4];
这24个排列隐含着已排好序的条件，所有找出第9个排列就简单了，只要不断收缩区间，直到为区间长度为1就是最终结果了。

在n = 4的时候，找第9个排列，9 > 6 * 1 ,跳过一个区间，index = 9 - 1/6 = 1，第一个数字是2，新可选数组[1,3,4]。
下次搜索n = 3时，k = 9 - 6 = 3;

那么3的阶乘recursion = 6,6个排列划分为3个区间，每个区间长度divide = 2;
在k = 3，index = 3 - 1 / 2 = 1,第二个数字是3，新可选数组[1,4]。
下次搜索n = 2时，k = 3 - 2 = 1;

2的阶乘recursion = 2,2个排列划分为2个区间，每个区间长度divide = 1;
在k = 1,index = 1 - 1 / 1 = 0,第三个数字是1,新可选数组[4]。

divide = 1的时候直接选4，最终结果2314。




### 代码

```java
class Solution {
    public String getPermutation(int n, int k) {
        if(n > 9 || n < 1){
            throw new IllegalArgumentException();
        }
        if(k < 1){
            throw new IllegalArgumentException();
        }
        List<Integer> nums = new ArrayList<>();
        for(int i = 0; i < n; i++){
            nums.add(i+1);
        }
        // recursion为当前n的阶乘
        int recursion = recursion(n);
        return recursive(n,k,recursion,new StringBuilder(),nums);
    }

    private String recursive(int n,int k,int recursion,StringBuilder s,List<Integer> nums){
        if(nums.size() == 1){
            return s.append(nums.remove(0)).toString();
        }
        int divide = recursion / n;
        int index = k==0?0:(k - 1)/divide;
        s.append(nums.remove(index));
        return recursive(n-1,k - index * divide,divide,s,nums);
    }

    private int recursion(int n){
        if (n == 1){
            return 1;
        } else if(n < 1){
            throw new IllegalArgumentException();
        } else {
            return n * recursion(n - 1);
        }
    }
}
```