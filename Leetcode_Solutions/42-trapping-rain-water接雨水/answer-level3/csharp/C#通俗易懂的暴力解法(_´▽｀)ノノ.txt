总之就是从左遍历到右找凹陷的地方，填满水，再从右遍历到左找凹陷的地方，填满水，就OK啦）
```
public class Solution {
    public int Trap(int[] height) {
        int answer=0;
        int temp=0;
        int[] rain=new int[height.Length];
        int max=0;
        int i,j,k;

        //先找到第一个柱子！
        for(i=0;i<height.Length-1;i++){
            if(height[i+1]<height[i]){
                max=height[i];
                break;
            }
        }
        //找到了！接下来开始装水了！
        for(;i<height.Length;i++){
            for(j=i;j<height.Length;j++)
            {
                if(height[j]>=max){
                    //把i到j的雨水都统计进rain！
                    for(k=i;k<=j;k++){
                        if(max-height[k]>rain[k]){
                            rain[k]=max-height[k];
                        }
                    }
                    max=height[j];
                    i=j+1;
                }
            }
        }
        
        
        //从右到左再来一次！
        for(i=height.Length-1;i>0;i--){
            if(height[i-1]<height[i]){
                max=height[i];
                break;
            }
        }
        
        //找到了！接下来开始装水了！
        for(;i>=0;i--){
            for(j=i;j>=0;j--)
            {
                if(height[j]>=max){
                    //把i到j多装了多少雨水都统计进rain！
                    for(k=j;k<=i;k++){
                        if(max-height[k]>rain[k]){
                            rain[k]=max-height[k];
                        }
                    }
                    max=height[j];
                    i=j-1;
                }
            }
        }
        
        //把rain里所有元素加一起就是答案啦！
        for(i=0;i<rain.Length;i++){
            answer+=rain[i];
        }
        return answer;//大功告成！
    }
}
```
