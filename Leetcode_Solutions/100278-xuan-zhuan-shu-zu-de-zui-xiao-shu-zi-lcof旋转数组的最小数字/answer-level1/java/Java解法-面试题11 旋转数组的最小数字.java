
### 代码

```java
/**
 * 本题目为Leetcode-cn.com
 * 剑指Offer专栏
 * 面试题11 旋转数组的最小数字
 * 题目链接:https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
 */

 //本题用到的主要思路是二分查找法,关键在于找到旋转数组的旋转点
class Solution {
    public int minArray(int[] numbers) {
        int length = numbers.length; //数组长度
        int i = 0;  //初始化索引位置,第一个在数组开头
        int j = length - 1;  //初始化索引位置,第二个在数组末尾
        
        while(i < j){  
            int m = (i + j) / 2;           //二分查找的中间位置
            if(numbers[m] > numbers[j]){   //如果中间位置大于末尾位置,则表示该旋转点在右排序数组
                i = m + 1;                  //第一个索引改为中间索引的下一个位置
            }else if(numbers[m] < numbers[j]){   //如果中间位置小于末尾位置,则表示该旋转点在左排序数组
                j = m;              //第二个索引改为中间索引
            }else{
                /**
                 * 中间位置等于末尾位置,则会产生两种情况
                 * 1.旋转点在左排序数组,例如[0,2,3,3,3]
                 * 2.旋转点在右排序数组,例如[3,3,3,2,3]
                 * 所以只能缩小第二个索引的范围
                 */
                j --;
            }
        }
        return numbers[i];

        /**
         * 注意:此题目的关键在于判断旋转点是在左排序数组还是在右排序数组
         * numbers[i]与numbers[m]的比较不具有旋转点位置的唯一性
         */
    }
}
```