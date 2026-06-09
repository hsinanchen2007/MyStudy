先用的暴力，提交后倒数第二个没过，超时了。
查询前可以先计算出A中偶数和sum，由于每次查询只更改A中一个数，所以可以根据当前要更改的数为奇偶，调整sum。


```
class Solution {
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int len=queries.length;
        int[] answer=new int[len];
        int sum=0;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0)
                sum+=A[i];
        }//求得A中偶数和sum

        for(int i=0;i<len;i++){
            if(A[queries[i][1]]%2==0)//当前要更改的数为偶数，先减去
                sum-=A[queries[i][1]];

            A[queries[i][1]]+=queries[i][0];
            if(A[queries[i][1]]%2==0)//若调整后的数字为偶数，则加到sum里，若为奇数，则不加
                sum+=A[queries[i][1]];
            answer[i]=sum;
        }
        return answer;
    }
}
```
