申请1个array记录，index是数位和，value是相同数位和的数字的个数，因为输入最大范围为10^4，所以数位和结果最大是4*9=36，所以array大小设37就好啦，
第一次forloop记录每个相同sum结果的数字的个数，第二次forloop遍历找并列最多的数量（其实也用不了37次）

```java
public int countLargestGroup(int n) {
        if(n < 9) return n;
        int[] bit_sum = new int[37];
        for(int i = 1; i <= n; i ++){
            int temp = i;
            int sum = 0;
            while(temp > 0){
                sum += temp % 10;
                temp /= 10;
            }
            bit_sum[sum] ++;
        }
        int max = 1;
        int ans = 1;
        for(int i = 1; i < 38; i++){
            if(bit_sum[i] > max){
                max = bit_sum[i] ;
                ans = 1;
            }else if(bit_sum[i]  == max){
                ans += 1;
            }else{
                break;
            }
        }

        return ans;
    }
```
