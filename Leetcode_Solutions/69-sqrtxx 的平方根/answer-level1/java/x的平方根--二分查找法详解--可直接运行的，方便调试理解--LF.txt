```
package ZJM_69_x的平方根;

public class Main {
    public static void main(String[] args) {
        int num1 = 4;
        int num2 = 8;

        Solution solution = new Solution();
        System.out.println(solution.mySqrt(num1));
        System.out.println(solution.mySqrt(num2));
    }
}

class Solution {
    public int mySqrt(int x) {
//        注意：针对特殊测试用例，例如 2147395599，要把搜索的范围设置成长整型
        long left = 0;                          //注意0的特殊情况，所以此处将左边界设置为0
        long right = x/2+1;                     //注意1的特殊情况，所以此处将有边界设置为x/2+1
        while (left<right){                     //当左边界小于右边界时
            //注意，这里应该取右中位数，如果取左中位数，代码会进入死循环
            long mid = left+(right-left+1)/2;   //取得右中位数
            long square = mid*mid;              //得到右中位数的平方
            if(square>x){                       //当右中位数平方大于x
                right = mid - 1;                //右边界设置为中位数减1
            }else {
                left = mid;                     //左边界设置为中位数
            }
        }

        return (int)left;                       //当左边界大于右边界时，返回强制转换为int类型的左边界值
    }
}

/**
 * 本题有两种解法，一种是二分查找法，一种是牛顿迭代法
 * 我使用二分查找法解题，首先先设置二分查找的左右边界，
 * 以左边界小于右边界作为循环条件，
 * 取右中位数，如果取左中位数，left=mid，会进入死循环
 * 将右中位数的平方与x的值进行大小比较，以判断是将左边界缩减还是右边界缩减
 * 当左边界大于右边界时，返回强制转换为int类型的左边界值
 */

```
