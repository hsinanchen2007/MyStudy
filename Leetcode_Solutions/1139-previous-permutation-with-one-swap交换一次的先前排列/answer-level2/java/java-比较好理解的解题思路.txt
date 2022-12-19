执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :40 MB, 在所有 Java 提交中击败了100.00%的用户

第一次硬编码，超时了
第二次参考讨论区思路，自己重新写了一遍
思路：
1，反序扫描
2，两两比较，发现第一个左边比右边大的数就是目标要交换的第一个值A，记下数值和坐标
3，以A为起点，正序扫描A的右边，找到比A数值小的所有数中最大的一个就是交换的第二个值B
4，交换AB，返回结果。

代码如下：

class Solution {
    public int[] prevPermOpt1(int[] A) {
        int len = A.length;
        int index = -1;
         for (int i=len-1;i>0;i--)
         {
             if (A[i - 1] > A[i])
             {
                 index = i - 1;
                 break;
             }
         }
         if(index==-1)
         {
             return A;
         }
         int in = A[index];
         int ans = A[index+1];
         int result = index+1;
         for (int j = index+1;j<A.length;j++)
         {
             if (A[j]< in && A[j]>ans)
             {
                 ans = A[j];
                 result = j;
             }
         }
         A[index] = ans;
         A[result] = in;
         return A;
    }
}