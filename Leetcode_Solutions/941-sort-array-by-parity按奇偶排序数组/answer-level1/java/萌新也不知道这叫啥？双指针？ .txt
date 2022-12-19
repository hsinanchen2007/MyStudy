执行用时 : 3 ms , 在所有 Java 提交中击败了 94.23% 的用户 内存消耗 : 45.4 MB , 在所有 Java 提交中击败了 72.18% 的用户

定义一个新数组为将要返回的数组B，c，b分别指向B数组的第一个元素和最后一个元素，a指向A数组的第一个元素，然后循环判断，如果是偶数则
把A[a]附给B[c]  (正向赋值)，否则附给B[b] (反向赋值)。有点乱 见谅


```
class Solution {
    public int[] sortArrayByParity(int[] A) {
      int[] B = new int[A.length];
        int a=0,b=A.length-1;
        int c = 0;
        while(c<=b){
            if(A[a]%2 == 0){
                B[c] = A[a];
                c++;
            }else{
                B[b] = A[a];
                b--;
            }
            a++;
        }
        return B;
    }
}
```


