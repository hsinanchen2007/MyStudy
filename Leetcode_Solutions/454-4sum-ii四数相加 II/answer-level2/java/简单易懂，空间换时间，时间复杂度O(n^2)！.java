### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
       int lenA=A.length;
       int lenB=B.length;
       int lenC=C.length;
       int lenD=D.length;
       int[] c1=new int[lenA*lenB];
       int[] c2=new int[lenC*lenD];
       int k1=0;
       int k2=0;
       for(int i=0;i<lenA;i++){
           for(int j=0;j<lenB;j++){
              c1[k1++]=A[i]+B[j];
           }
       }
       for(int i=0;i<lenC;i++){
           for(int j=0;j<lenD;j++){
              c2[k2++]=C[i]+D[j];
           }
       }
       Arrays.sort(c1);
       Arrays.sort(c2);
       int lenC1=c1.length;
       int lenC2=c2.length;
       int ret=0;

       HashMap<Integer,Integer> map=new HashMap<>();

       for(int l=0;l<lenC2;l++){
           int times=map.getOrDefault(c2[l],0);
           map.put(c2[l],++times);
       }
       for(int i=0;i<lenC1;i++){
           int temp=0-c1[i];
           if(map.containsKey(temp)){
                    int times=map.get(temp);
                   ret+=times;
           }
       }
       return ret;
    }
}
```