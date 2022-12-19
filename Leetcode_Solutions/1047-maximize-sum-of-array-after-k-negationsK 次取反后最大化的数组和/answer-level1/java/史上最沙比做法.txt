### 解题思路
执行用时 :
2 ms
, 在所有 java 提交中击败了
75.05%
的用户
内存消耗 :
37.2 MB
, 在所有 java 提交中击败了
44.99%
的用户

### 代码

```java
class Solution {
    public int largestSumAfterKNegations(int[] A, int K) {
          int sum=0;
        int reduce=0;
        Arrays.sort(A);//升序排序
        //会检查数组个数大于286且连续性好就使用归并排序，若小于47使用插入排序，其余情况使用双轴快速排序
        for(int i=0;i<A.length;i++){
            if(A[i]<0&&K>0){
                A[i]*=-1;
                K--;
            }else if(A[i]==0&&K>0){
                for(int a:A){
                    sum+=a;
                }
                return sum;
            }else{
               if(K>0){
                    if(K%2==0){break;}
                    else {//走到这一步说明数组A此时已全为正数元素，但还中必须要有一个正元素变为负数，找最小正数
                        Arrays.sort(A);//找最小
                        A[0]*=-1;
                        break;

                    }
                }else{
                   break;
               }
            }
            if(K<=0) break;
        }

        for(int a:A){
            sum+=a;
        }
        return sum;
    }
}
```