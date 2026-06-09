### 解题思路
emm..可以一看反正。一开始想用最常用的依照题意法进行求解，但是提交超时，测试用例给了一个非常长的例子，我估计是循环嵌套导致的问题，接着转变思路，首先我先求出原数组中偶数之和，接着依照索引加上响应的数，如果这个值为偶，我们继续判断，如果原先的数组值为奇数，我们需要加上的是该奇数和依据索引增加的数之和，如果为偶数，我们只需要加上后来的值即可，如果原数组的数加上由索引找到的数的值为奇数，我们继续判断，如果原先的值为奇数，我们无需任何改动，如果为偶数，我们需要从和中去除该偶数，因为这个位置已经不再是偶数了，注意：每次执行完毕都要实时更新A数组中的值。（不知道能不能看懂，已经尽量讲的很详细了）

### 代码

```java
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int[] arr = new int[A.length];
        int sum = 0;
        for(int i:A) {
            if(i%2==0) {
                sum+=i;
            }
        }
        for(int i = 0;i<A.length;i++) {
            if((A[queries[i][1]]+queries[i][0])%2==0) {
                if(A[queries[i][1]]%2!=0){
                sum+=A[queries[i][1]]+queries[i][0];
                arr[i] = sum;
                }else {
                    sum+=queries[i][0];
                    arr[i] = sum;
                }
            }else  if(A[queries[i][1]]%2==0) {
                sum-=A[queries[i][1]];
                arr[i] = sum;
            }else {
                arr[i] = sum;
            }
        A[queries[i][1]]+=queries[i][0];


        }
        return arr;
    }
}
```