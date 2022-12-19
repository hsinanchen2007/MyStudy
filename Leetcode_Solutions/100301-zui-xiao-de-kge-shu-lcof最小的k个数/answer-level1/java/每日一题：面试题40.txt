### 解题思路
根据题目特点，arr中均为整数和"0 <= arr[i] <= 10000"可采用哈希表排序
### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int N = arr.length;
        int[] cnt = new int[10001];
        int[] ans = new int[k];

        for(int num :arr){
            cnt[num]++;
        }

        int idx = 0;
        for(int i = 0; i < N && idx < k ; i++){
            while(cnt[i] > 0 && idx < k){
                ans[idx++]=i;
                cnt[i]--;
            }
        }
        return ans;
    }
}
```