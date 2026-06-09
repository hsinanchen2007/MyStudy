# 思路
首先性质必须掌握：**一个数的各位相加之和能被3整除，那这个数就是3的倍数**

不会这条性质这个题没法做，那我们分两步来解决问题：

第一步我们既然想得到最大的数，首先将就要获得最长的数，也就是首先要确定删除的数字，那么很明显这里要按照**对3取余的结果进行对组**，并对所有数字求和，然后对这个和进行分类：
1. 数字和能被3整除，那么所有的数字我们都需要
2. 数字和整除3余1，那么我们首先考虑删除掉一个取余为1的数，如果没有就删除掉两个取余为2的树，并且都要删除最小值
3. 数字和整除3余2，那么我们首先考虑删除掉一个取余为2的数，如果没有就删除掉两个取余为1的树，并且都要删除最小值

第二步我们再将结果整合在一起，由于要获取最大值并且上述过程中删除数字也要删除对应组的最小值，因此需要使用排序算法。

使用比较排序时，时间复杂度为**O(lgn)**；但由于题目中给的数字范围为 **0 - 9**，因此可以使用桶排序进一步降低时间复杂度，为**O(n)**。

# 解法1：比较排序

```
// time complexity O(nlgn)
//space complexity O(n)
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        Arrays.sort(digits);
        List<Integer> rem1Indexs = new ArrayList<>();
        List<Integer> rem2Indexs = new ArrayList<>();
        int sum = 0;
        for(int i = 0; i < digits.length; i++){
            sum += digits[i];
            if(digits[i] % 3 == 1){
                rem1Indexs.add(i);
            } else if(digits[i] % 3 == 2){
                rem2Indexs.add(i);
            }
        }
        sum %= 3;
        if(sum == 1){
            if(!rem1Indexs.isEmpty()){
                return constructRes(digits, rem1Indexs.get(0), -1);
            } else {
                return constructRes(digits, rem2Indexs.get(0), rem2Indexs.get(1));
            }
        } else if(sum == 2){
            if(!rem2Indexs.isEmpty()){
                return constructRes(digits, rem2Indexs.get(0), -1);
            } else {
                return constructRes(digits, rem1Indexs.get(0), rem1Indexs.get(1));
            }
        }
        return constructRes(digits, -1, -1);
    }

    private String constructRes(int[] digits, int ignoreId1, int ignoreId2){
        StringBuilder res = new StringBuilder();
        for(int i = digits.length -1; i >= 0; i--){
            if(i == ignoreId1 || i == ignoreId2){
                continue;
            }
            res.append(digits[i]);
        }
        return res.length() > 0 && res.charAt(0) == '0' ? "0": res.toString();
    }
}
```

# 解法2：桶排序

```
// time complexity O(n)
//space complexity O(1)
class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int[] buckets = new int[10];
        int sum = 0;
        for(int i = 0; i < digits.length; i++){
            sum += digits[i];
            buckets[digits[i]]++;
        }
        sum %= 3;
        int rem1 = buckets[1] + buckets[4] + buckets[7];
        int rem2 = buckets[2] + buckets[5] + buckets[8];
        if(sum == 1){
            if(rem1 > 0){
                rem1--;
            } else {
                rem2 -= 2;
            }
        } else if(sum == 2){
            if(rem2 > 0){
                rem2--;
            } else {
                rem1 -= 2;
            }
        }
        StringBuilder res = new StringBuilder();
        for(int i = 9; i >= 0; i--){
            if(i % 3 == 1){
                while(rem1 > 0 && buckets[i] > 0){
                    buckets[i]--;
                    rem1--;
                    res.append(i);
                }
            } else if(i % 3 == 2){
                while(rem2 > 0 && buckets[i] > 0){
                    buckets[i]--;
                    rem2--;
                    res.append(i);
                }
            } else {
                while(buckets[i] > 0){
                    buckets[i]--;
                    res.append(i);
                }
            }
        }
        return res.length() > 0 && res.charAt(0) == '0' ? "0": res.toString();
    }
}
```