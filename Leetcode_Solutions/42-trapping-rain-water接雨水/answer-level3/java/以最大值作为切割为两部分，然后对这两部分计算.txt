### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {

        int len = height.length;
        int max = 0;
        for(int i=1;i<len;i++){
            if(height[i]>height[max]){
                max =i;
            }
        }
        return trap(height,0,max)+ trap(height,max,len-1);  
    }

    public int trap(int[] height,int f,int e){
        if(e-f<=1){
            return 0;
        }
        int temp=0;
        if(height[f]<height[e]){
            int min = height[f];
            for(int i = f+1;i<e;i++){
                if(height[i]>min){
                    min = height[i];
                }else{
                    temp =temp + min -height[i];
                }
            }
        }else{
            int min = height[e];
            for(int i = e-1;i>f;i--){
                if(height[i]>min){
                    min = height[i];
                }else{
                    temp =temp + min -height[i];
                }
            }
        }
        return temp;
    }
}
```