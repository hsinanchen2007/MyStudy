![WX20191116-194441@2x.png](https://pic.leetcode-cn.com/3b5d1a157657b16e48d25d1932f829cd1c5776e8aaa95275e26747ac914a5709-WX20191116-194441@2x.png)

```
public int removeDuplicates(int[] nums){
        /*当数组为null或没元素时直接返回*/
        if(nums==null||nums.length<1){
            return 0;
        }
        /*定义一个可替换下标指针，从第二个元素开始*/
        int index=1;
        /*定义没有重复元素的数组长度*/
        int newLength=1;
        /*定义一个遍历指针，从第二个元素开始，要小于数组大小*/
        int p=1;
        while (p<nums.length){
            /*当前元素与前一个元素不相等时，给index处下标赋值为p处下标的值，并且index+1和没有重复元素的数组长度加1*/
            if(nums[p]!=nums[p-1]){
                    nums[index++]=nums[p];
                    newLength++;
            }
            p++;
        }
        return newLength;
    }
```
