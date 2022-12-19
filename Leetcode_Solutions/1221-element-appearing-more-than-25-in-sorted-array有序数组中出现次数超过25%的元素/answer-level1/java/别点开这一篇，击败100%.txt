### 解题思路
因为这个是一个有序的数组，而且仅有一个数字的个数超过25%

所以只需要在遍历每个元素的时候，去对比当前的元素arr[i] 与 arr[i + (int)(arr.length * 0.25)]是否一致即可

更暴力的解法，例如计算出每个元素的数量再对比是否大于25%，但这也不是好办法。

### 代码

```java
class Solution {
    public int findSpecialInteger(int[] arr){
        if(arr.length <= 3) return arr[0];
        int std = (int)(arr.length * 0.25), ans = 0;
        for(int i = 0; i < arr.length - std; i++){
            if(arr[i] == arr[i + std]){
                ans = arr[i];
                break;
            }
        }
        return ans;
    }
}


// class Solution {
//     public int findSpecialInteger(int[] arr) {

//         if(arr.length <= 3) return arr[0];

//         int std = (int)(arr.length * 0.25), ans = 0;

//         HashMap<Integer, Integer> count = new HashMap<>();
//         for(int num : arr){
//             count.put(num, count.getOrDefault(num, 0) + 1);
//             if(count.get(num) > std){
//                 ans = num;
//                 break;
//             }
//         }
//         return ans;
//     }
// }    
```