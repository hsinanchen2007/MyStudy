### 解题思路
先找出arr1中出现的元素，然后再用两个list找出未出现的元素，加入最终存放结果的list。

### 代码

```java
class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        List<Integer> list = new ArrayList<>();//最终结果存放
        List<Integer> temp = new ArrayList<>();//存放arr2
        List<Integer> res = new ArrayList<>();//存放未出现的元素
        //双层循环找出相对排序数组
        for(int i = 0;i<arr2.length;i++){
            for(int j = 0;j<arr1.length;j++){
                if(arr1[j] == arr2[i]){
                    list.add(arr1[j]);
                }
            }
        }
        for(int n : arr2){
            temp.add(n);
        }
        //找出未出现的元素
        for(int i = 0;i<arr1.length;i++){
            if(!temp.contains(arr1[i])){
                res.add(arr1[i]);
            }
        }
        Collections.sort(res);//排序，然后添加进最终结果
        for(int n : res){
            list.add(n);
        }
        int[] ans = new int[list.size()];
        for(int i = 0;i<list.size();i++){
            ans[i] = list.get(i);
        }
        return ans;
    }
}
```