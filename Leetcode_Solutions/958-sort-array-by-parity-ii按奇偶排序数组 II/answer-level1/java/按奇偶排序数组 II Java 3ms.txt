### 解题思路
依题意可知：奇数放在奇数索引的位置，偶数放在偶数索引的位置。
- 新建两个索引，分别指向奇数位置和偶数位置；
- 新建一个数组来存放结果；
- 遍历数组，若当前值为奇数，则将值放在奇索引的位置，并将索引加2；偶数同样操作。
### 代码
```java
class Solution {
    public int[] sortArrayByParityII(int[] A) {
        int[] res=new int[A.length];
        int odd=1,even=0;
        for(int i=0;i<A.length;i++){
            if(A[i]%2==0){
                res[even]=A[i];
                even+=2;
            }else{
                res[odd]=A[i];
                odd+=2;
            }
        }
        return res;
    }
}
```