**方法一：使用双指针**
```
class Solution {
    /**
    * 思路：
    * 由题符合条件的数组和可以除尽3没有余数并且分成和相等的三部分每部分都不为空。
    * (1) 算出数组总和，如果除以3有余数直接返回false，反之往下执行。
    * (2) 定义两个指针分别从数组两边分别叠加，
    *   查找存在两边叠加和均为数组总和的三分之一并且两个数组之间仍然有数字的情况。
    */
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int a : A){
            sum += a;
        }
        if(sum%3 != 0){
            // 总和不是3的倍数，直接返回false
            return false;
        }

        // 使用双指针,从数组两头开始一起找，节约时间
        int left = 0;
        int leftSum = A[left];
        int right = A.length - 1;
        int rightSum = A[right];

        // 使用left + 1 < right 的原因，防止只能将数组分成两个部分
        // 例如：[1,-1,1,-1]，使用left < right作为判断条件就会出错
        while(left + 1 < right){
            if(leftSum == sum/3 && rightSum == sum/3){
                // 左右两边都等于 sum/3 ，中间也一定等于
                return true;
            }
            if(leftSum != sum/3){
                // left = 0赋予了初值，应该先left++，在leftSum += A[left];
                leftSum += A[++left];
            }
            if(rightSum != sum/3){
                // right = A.length - 1 赋予了初值，应该先right--，在rightSum += A[right];
                rightSum += A[--right];
            }
        }
        return false;  
    }
}
```

**方法二：遍历和为数组总和三分之一的位置**
```
class Solution {
    /**
    * 思路：
    * (1) 算出数组总和，如果除以3有余数直接返回false，反之往下执行。
    * (2) 遍历数组，从0开始累加等于总和的三分之一则次数加一并从0开始重新累加。
    * (3) 遍历完之后，若累加等于总和三分之一的次数超过三次则符合要求。
    */
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i: A){
            sum += i;
        }
        if(sum%3 != 0){
            // 总和不是3的倍数，直接返回false
            return false;
        }
        int s = 0;
        int flag = 0;
        for(int i:A){
            s += i;
            if(s == sum/3){
                flag++;
                s = 0;
            }
        }
        // flag不一定等于3，例如[1,-1,1,-1,1,-1,1,-1]
        return flag >= 3;
    }
}
```
