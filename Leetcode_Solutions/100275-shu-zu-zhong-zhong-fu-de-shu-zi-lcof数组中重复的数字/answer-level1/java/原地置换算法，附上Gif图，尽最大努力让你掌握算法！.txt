思路：**巧妙利用数组下标来匹配对应的元素，从前往后遍历数组，每个元素都要求下标与元素的值一一对应，如果在调换位置的过程中发现该位置的元素与别的位置的元素是相同的，那么就说明该数字重复，直接返回该数字**
![ezgif.com-resize.gif](https://pic.leetcode-cn.com/811320fa207519efeac59b157842938b61e4ec059ab9bc0ffa392babbd42da97-ezgif.com-resize.gif)

```
public static int findRepeatNumByNon(int[] arr){
    for (int i = 0; i < arr.length; i++){
        //将数字与下标对应起来
        while (arr[i] != i){
            int temp = arr[i];
            //如果准备移动的数字已经等于对应位置上的数字则说明数字重复
            if(temp == arr[temp]) return temp;
            arr[i] = arr[temp];
            arr[temp] = temp;
        }
    }
    return Integer.MAX_VALUE;
}
```
**时间复杂度：O(n)，空间复杂度：O(1)**
当遇到利用数组表示数据的时候，可以多点考虑使用数组的下标进行解题，数组的下标有时候会给你意想不到的惊喜！