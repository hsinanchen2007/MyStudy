### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int trap(int[] height) {
        if(height == null || height.length == 0){
            return 0;
        }
        int left = 0;
        int l_index = 0;
        int right = 0;
        int r_index = 0;
        int cnt = 0;
        boolean isMax = false;
        for(int i = 0; i < height.length; i++){
            if(left == 0 && height[i] > 0){
                left = height[i];
                l_index = i;
            }
            if(left != 0 && i > l_index && height[i] >= left){
                right = height[i];
                r_index = i;
                for(int j = l_index + 1; j < r_index; j++){
                    int temp = left - height[j];
                    cnt += temp;
                }
                left = height[i];
                l_index = i;
            }else{
                if (i < l_index){
                    continue;
                }
                int tempmax = 0;
                int tempindex = 0;
                for(int j = l_index + 1; j < height.length; j++){
                    if(height[j] > height[i]){
                        break;
                    }else{
                        if(j == height.length - 1){
                            isMax = true;
                            break;
                        }
                    }
                }
                if(isMax){
                    for(int j = l_index + 1; j < height.length; j++) {
                        if (height[j] > tempmax) {
                            tempmax = height[j];
                            tempindex = j;
                        }
                    }
                    for (int k = l_index + 1; k < tempindex; k++){
                        int temp = tempmax - height[k];
                        cnt += temp;
                    }
                    left = tempmax;
                    l_index = tempindex;
                    isMax = false;
                }
            }
        }
        return cnt;
    }
}
```