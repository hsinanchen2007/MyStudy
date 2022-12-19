### 解题思路
此处撰写解题思路
双指针大法好啊，哈哈哈哈哈 好多题都是用的这个万金油大法
建立双指针从左右两侧 向中间遍历 积水的大小和左右的最高处有关系。

### 代码

```java
class Solution {
    public int trap(int[] height) {
        int left_max = 0;//左侧最大值
        int right_max = 0;//右侧最大值
        int sum = 0;//水的总体积
        int i = 0;//左边开始的指针位置
        int j = height.length - 1;//右边开始的指针位置
        while(i<j){
            if(height[i]<height[j]){//如果左边的最高高度低于最右边的 则在左边判断
                if(height[i]>left_max){//如果所指位置大小比左边最大值大
                    left_max = height[i];//则最大值替换
                }else{
                    sum += left_max - height[i];//反之，积水等于最大值减去目前位置的高度
                    i++;//左边前进一格
                }
            }else{
                if(height[j]>right_max){//右边同左边同理
                    right_max = height[j];
                }else{
                    sum += right_max - height[j];
                    j--;
                }
            }
        }
        return sum;
    }
}
```