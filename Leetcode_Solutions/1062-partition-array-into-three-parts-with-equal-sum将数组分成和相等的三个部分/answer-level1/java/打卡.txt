### 解题思路
一开始看题我以为不是按顺序这样分三块，后来仔细一看例子原来是顺序的。那没事了，也没啥思想，就正常做，因为数组长度不大所以时间差别不大，用双指针应该会快length/3吧。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int length=A.length;
        if(length==0){
            return false;
        }
        int total=0;
        for(int i=0;i<length;i++){
            total+=A[i];
        }
        if(total%3!=0){
            return false;
        }
        int sum=0;
        int count=0;
        for(int j=0;j<length;j++){
            sum+=A[j];
            if(sum==total/3){
                count++;
                sum=0;
            }
        }
        if(count>=3){//测试时候全是0的反例
            return true;
        }
        else{
            return false;
        }
    }
}
```