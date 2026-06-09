![微信图片_20200311063604.png](https://pic.leetcode-cn.com/0da7fef0c5ed17416fade47248acaf4c13ed18177db92342fd9612c69a5456f2-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200311063604.png)

前判断数组长度小于三，就返回false
然后判断所有元素和是否是三的倍数，否返回false
设置前指针0，后指针length-1，往前加到和/3 ,若指针有重合（前>后）则返回false
最后求中间部分的和，三部分和一样则返回true
```
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int length = A.length;
        if(length <= 2){
            return false;
        }
        int sum=0;
        for(int i = 0;i < length;i++){
            sum += A[i];
        }
        if(sum % 3 != 0){
            return false;
        }
        sum = sum / 3;
        int sumA = A[0],sumB = 0,sumC = A[length-1];
        int j = 1; 
        while(sumA != sum&&j < length){
            sumA += A[j];
            j++;
        }
        int m = length -2;
        while(sumC != sum&&m >= 0){
            sumC += A[m];
            m--;
        }
        if(j > m){
            return false;
        }
        for(int t = j;t < m+1;t++){
            sumB += A[t];
        }
        if(sumC == sumB&&sumB == sumA){
            return true;
        }
        else{
            return false;
        }
    }
}
```

```

