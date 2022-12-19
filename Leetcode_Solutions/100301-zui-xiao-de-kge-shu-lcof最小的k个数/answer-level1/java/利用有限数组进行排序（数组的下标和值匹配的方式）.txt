### 解题思路
1.数组中最的的数值为10000，则可以创建一个长度为10001的数组，遍历把所有的数字按照其值和下标的匹配放入该数组中，当某个数字重复出现是，该下标对应的值加一；
2.从有序的数组中取出k个元素，需注意每个元素是有几率重复出现的，其值代表该元素出现的次数；

### 代码

```java
class Solution {
    public int[] getLeastNumbers(int[] arr, int k) {
        int[] tmpArr = new int[10001];
        for(int a : arr) {
            tmpArr[a]++;
        }
        int[] res = new int[k];
        int index = 0;
        for(int i = 0; i < 10001; i++) {
            if(index == k) {
                break;
            }
            if(tmpArr[i] == 0) {
                continue;
            }
            for(int j = 0; j < tmpArr[i] && index < k; j++) {
                res[index] = i;
                index++;
            }
        }
        return res;
    }
}
```