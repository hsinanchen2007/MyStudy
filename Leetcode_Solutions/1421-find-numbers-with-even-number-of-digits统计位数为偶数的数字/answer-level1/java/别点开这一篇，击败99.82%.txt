### 解题思路
试了三种方法，没想到最高还只是99.82%

第一个想法是转成字符串，然后看字符串的长度是否为偶数

第二个方法是 数学除以10，根据可除的数量来判断是否为偶数

第三个方法是 根据题目的限定条件，因为数字小于1万，所以可以根据区间来判断奇数偶数

### 代码

```java
class Solution {
    public int findNumbers(int[] nums){
        int ans = 0;
        for(int num : nums){
            if(num >= 10 && num <= 100 || num >= 1000 && num < 10000)
                ans++;
        }
        return ans;
    }
}


// class Solution {
//     public int findNumbers(int[] nums){

//         int ans = 0;
//         for(int num : nums){
//             int n = 0;
//             while(num > 0){
//                 num /= 10;
//                 n++;
//             }
//             ans += n % 2 == 0 ? 1 : 0;
//         }
//         return ans;
//     }
// }


// class Solution {
//     public int findNumbers(int[] nums) {

//         int even = 0;
//         for(int num : nums){
//             String numStr = num + "";
//             if(numStr.length() % 2 == 0)
//                 even++;
//         }
//         return even;
//     }
// }
```