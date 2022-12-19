### 解题思路
根据连续的数列的长度count来遍历，区分长度的奇偶
1、数列长度为奇数，如果N%count==0 肯定存在有效的数列
2、数列长度为偶数，如果N%count==0，肯定不行，因为偶数长度的数列均值肯定不是整数必是xxx.5这种形式，所以如果N*2%count=0，肯定满足条件

最后就是循环终止条件，我的判断是N/count为均值，这个均值必须>=(count+1)/2，否则会取到0和负数
### 代码

```java
class Solution {
    public int consecutiveNumbersSum(int N) {
        int res = 1;
        int count = 2;
        while(N/count>=(count+1)/2){
            if(count%2==1){
                if(N%count==0){
                    ++res;
                }
            } else{
                if(N%count!=0 && (N*2)%count==0){
                    ++res;
                }
            }
            ++count;
        }
        return res;
    }
}
```