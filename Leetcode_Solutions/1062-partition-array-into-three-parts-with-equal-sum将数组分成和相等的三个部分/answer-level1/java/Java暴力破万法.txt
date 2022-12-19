### 解题思路
条件限定必须 A = B = C
所以先累计求和,判断对三取余是否为零,不为零直接返回false

定义前后两个指针以及一个临时变量
先得到头部
再得到尾部

最后中间有两种情况,分别做判断
第一种情况是只有一个数值
第二种情况是多个数值

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int a : A) {
            sum += a;
        }
        if (sum % 3 == 0) {
            int left = 0;
            int right = A.length - 1;
            int temp = 0;
            int mid = sum / 3;
            while(left < right){
                temp += A[left++];
                if(temp == mid){
                    temp = 0;
                    break;
                }
            }
            while(right > left){
                temp += A[right--];
                if(temp == mid){
                    temp = 0;
                    break;
                }
            }

            if(right == left){
                return A[left] == mid;
            }
            
            return left < right && temp == 0;
        } else {
            return false;
        }
    }
}
```