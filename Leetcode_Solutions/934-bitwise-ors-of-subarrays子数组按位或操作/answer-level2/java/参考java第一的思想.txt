基本思想官方题解里已经解释了，就是当累计的或结果满足32全是1的状态时就不再发生变化了。后面的结果就可以不用计算了
```
public int subarrayBitwiseORs2(int[] A) {
        HashSet<Integer> set = new HashSet<>();
        int n = A.length;
        for(int i = 0; i < n; i++){
            set.add(A[i]);
            for(int j = i - 1; j >= 0; j--){
                if((A[i] & A[j]) == A[i]) break;//这个说明，A[j]已经为32位全是1的状态了，无需进行后续操作了
                A[j] |= A[i];   //这里的A[j]的值表示从A[j]|...|A[i]的结果，存贮下来下一轮使用 dp思想
                set.add(A[j]);  //比如这里i=4,那么A[j] j>=0&&j<=3 就表示A[0]|..|A[4] A[1]|..|A[4] A[2]|..|A[4] A[3]|A[4]
             }
        }
        return set.size();
    }
```
