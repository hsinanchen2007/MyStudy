### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
  int d=height.length;  //矩形的宽度(数组的长度)
        int max=0;  //记录柱子的最大高度
        int m=0;
        int n=0;
        int s1=0;    //从左往右遍历
        int s2=0;    //从右往左遍历
        int s3=0;    //柱子面积
        for (int i=0;i<height.length;i++){
            s3+=height[i];
            if (max<height[i]){
                max=height[i];
            }
            if (m>=height[i]){
                s1+=m;
            }
            if (m<height[i]){
                m=height[i];
                s1+=height[i];
            }
        }

        for (int i=height.length-1;i>=0;i--){
            if (n>=height[i]){
                s2+=n;
            }
            if (n<height[i]){
                n=height[i];
                s2+=height[i];
            }
        }
        int s0=s1+s2-d*max-s3;
        return s0;
    }
}
```