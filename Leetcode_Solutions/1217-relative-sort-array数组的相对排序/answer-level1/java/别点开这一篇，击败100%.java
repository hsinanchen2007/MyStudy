### 解题思路
先计算arr1中各个元素的数量（因为arr1是数组组合，且最大不超过1000，所以可以用数组本身的索引当做arr1中的元素。）

然后把arr2中有的元素对照arr1中的数量添加到ans中

因为arr1在第一步计算数量的时候，已经按索引的方式升序排序了，所以后面只要按顺序遍历就可以了。

PS：后面注释的是一开始写的，思路大致相同，但是没想到可以用索引值来记录arr1中的元素，所以越写bug越多，最终冗杂不堪。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2){
        int[] nums = new int[1001];
        int[] ans = new int[arr1.length];

        for(int num : arr1) 
            nums[num]++;

        int index = 0;
        for(int i : arr2){
            while(nums[i]-- > 0)
                ans[index++] = i;
        }

        for(int i = 0; i < nums.length; i++){
            while(nums[i]-- > 0)
                ans[index++] = i;
        }
        return ans;
    }
}


// class Solution {
//     public int[] relativeSortArray(int[] arr1, int[] arr2) {
//         int len1 = arr1.length;

//         int[] ans = new int[len1];

//         //统计arr1中各个数字的数量
//         Map<Integer, Integer> map = new HashMap<>();
//         for(int num : arr1){
//             map.put(num, map.getOrDefault(num, 0) + 1);
//         }

//         int index = 0;
//         List<Integer> temp = new ArrayList();

//         for(int num : arr2){
//             temp.add(num);
//             if(map.containsKey(num)){
//                 int count = map.get(num); 
//                 while(count-- > 0){
//                 ans[index++] = num;
//                 }

//             }
            
//         }

//         int[] arrLeft = new int[len1];
//         int leftIndex = index;
//         for(int num : arr1){
//             if(!temp.contains(num)){
//                 arrLeft[leftIndex++] = num;
//             }
//         }

//         Arrays.sort(arrLeft);

//         for(int i = index; i < len1; i++){
//             ans[i] = arrLeft[i];
//         }

//         return ans;
//     }
// }
```