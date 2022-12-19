![image.png](https://pic.leetcode-cn.com/ae4ea51dd535e13f819cb05151b7605e286f2deaa3cdadc41b4c1d2780f33dd3-image.png)


```
class Solution {
    public void duplicateZeros(int[] arr) {
    
        int [] num = new int [arr.length];
        int [] arrcopy = new int[arr.length];
        
        for (int i = 0; i < arr.length; i++){
            //赋值一个与原数组一样的数组
                arrcopy[i] = arr[i];
        }
        int dis = 0;
        for (int i = 0; i < arr.length; i++){
            //记录因为0的出现，导致的每一个元素应该偏移的量dis，记录于num数组。
            if (arr[i] == 0){
                dis++;
            }
            num[i] = dis;
        }
        //如果没有0，直接返回了
        if (dis==0)return;
        //初始化原数组，置为0
        for (int i = 0; i < arr.length; i++){
            arr[i] = 0;   
        }
       //偏移量作用
        for (int i = 0; i + num[i] < arr.length; i++){
            arr[i+num[i]] = arrcopy[i];
        }
    }
}
```

解法二：插入排序思路，比较慢大概40%

```
class Solution {
    public void duplicateZeros(int[] arr) {
    
        for (int i = 0; i < arr.length; i++){
           if (arr[i] == 0){
               for (int j = arr.length - 1; j > i; j--){
                   arr[j] = arr[j-1];
               }
               i++;
           }
            
        }
    }
}
```


