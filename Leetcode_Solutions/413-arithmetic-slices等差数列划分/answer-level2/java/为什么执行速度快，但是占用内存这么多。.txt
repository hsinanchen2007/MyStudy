### 解题思路
此处撰写解题思路
执行用时 :0 ms, 在所有 Java 提交中击败了100.00% 的用户
内存消耗 :37.3 MB, 在所有 Java 提交中击败了5.37%的用户


### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        //init
        int len = A.length;

        //base case
        if(len<3) return 0;

        //start
        int sum=0;
        for(int i=0;i<len-2;i++){
            for(int j=i;j<len-2;j++){
                if(A[j]-A[j+1] == A[j+1]-A[j+2]){
                    sum =sum + 1;
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return sum;
    }
}
```