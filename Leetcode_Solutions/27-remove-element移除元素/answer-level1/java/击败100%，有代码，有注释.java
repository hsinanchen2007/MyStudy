![WX20191116-200520@2x.png](https://pic.leetcode-cn.com/817eec9dd9658cd9fe27c042bbb20efe220e0ea4ed49e615403a27da611032e0-WX20191116-200520@2x.png)

```
public int removeElement(int[] nums,int val){
        /*当数组为null或没元素时直接返回*/
        if(nums==null||nums.length<1){
            return 0;
        }
        /*定义一个可替换下标指针，从第一个元素开始*/
        int index=0;
        /*定义没有指定元素的数组长度*/
        int newLength=0;
        /*定义一个遍历指针，从第一个元素开始，要小于数组大小*/
        int p=0;
        while (p<nums.length){
            /*当前元素与指定数字不相等时，给index处下标赋值为p处下标的值，并且index+1和没有指定元素的数组长度加1*/
            if(nums[p]!=val){
                nums[index++]=nums[p];
                newLength++;
            }
            p++;
        }
        return newLength;
    }
```
