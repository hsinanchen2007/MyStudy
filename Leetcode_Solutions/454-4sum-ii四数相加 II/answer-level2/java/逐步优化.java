### 解题思路
**方法一**：o(n^4)做法 代码略 超时
**方法二**：o(n^3*logn)做法  排序+二分  超时46/48
代码：
```
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        if(A==null||A.length==0) return 0;
        int n=A.length,cnt=0;
        Arrays.sort(A);
        Arrays.sort(B);
        Arrays.sort(C);
        Arrays.sort(D);
        if(A[0]+B[0]+C[0]+D[0]>0) return cnt;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int sum=A[i]+B[j]+C[k];
                    int find=0-sum;
                    int l=0,r=n-1;
                    while(l<r){
                        int mid=(l+r)/2;
                        if(D[mid]>=find) r=mid;
                        else l=mid+1;
                    }
                    if(D[l]!=find) continue;
                    int tmp=l;
                    r=n-1;
                    while(l<r){
                        int mid=(l+r+1)/2;
                        if(D[mid]<=find) l=mid;
                        else r=mid-1;
                    }
                    cnt+=r-tmp+1;
                }
            }
        }
        return cnt;
    }
}
```
**方法三**：o(n^3)做法 HashMap存放最后一层循环的数据 超时 47/48
代码：
```
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        if(A==null||A.length==0) return 0;
        int n=A.length,cnt=0;
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int x:D) map.put(x,map.getOrDefault(x,0)+1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    int sum=A[i]+B[j]+C[k];
                    int find=0-sum;
                    if(map.containsKey(find)) cnt+=map.get(find);
                }
            }
        }
        return cnt;
    }
}

```

**方法四**：o(n^2)做法 同方法三 只是把两层循环的和放入HashMap 通过

### 代码

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        if(A==null||A.length==0) return 0;
        int n=A.length,cnt=0;
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=A[i]+B[j];
                map.put(sum,map.getOrDefault(sum,0)+1);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int sum=C[i]+D[j];
                int find=0-sum;
                if(map.containsKey(find)) cnt+=map.get(find);
            }
        }
        return cnt;
    }
}
```