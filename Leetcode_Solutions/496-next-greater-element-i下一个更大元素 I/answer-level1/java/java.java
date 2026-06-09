### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {//我比较菜，只能用这种又笨的方法写出来了。但是///一会去看大佬 们写的方式 再写一次
        Stack<Integer> stack = new Stack<Integer>();//用来存放结果的stack
        Integer count = new Integer(-1);//当没有比这个数大时，输入-1
        for(int i=0;i<nums1.length;i++){//拿 出第一个nums1中的元素
            for(int j =0;j <nums2.length;j++){//在nums2中找到nums1元素的位置
                if(nums1[i]==nums2[j]){//如果找到了
                    int bijiao=nums1[i];//把nums1的元素值先给bijiao
                    for(int f = j+1;f<nums2.length;f++){//从nums2的j+1往后对比，有没 有比这个bijiao大的、比如4
//在nums2中的位置是2，那我们就从3的位置和这个元素比较
                        if(bijiao<nums2[f]){
                            stack.push(nums2[f]);//比他大的入栈
                            break;//结束本循环，

                    }
                    }
                    break;//结束本循环，

                }
            }
            if(i==stack.size()){//如果 循环完了，栈的大小和i的大小相等。说明 在循环里没有数字入栈。也就没有找到比
//这数字大的，那么入栈-1
                stack.push(count);
            }
        }
        int size = stack.size();
        int[] ret = new int[size];
        for(int i =size-1;i>=0;i--){
            ret[i]=(int)stack.pop();
        }
        return ret;
    }
}
```