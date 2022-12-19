### 解题思路
此处的思路是 【木桶原理】
木桶能接的水，取决于最短板
把数组的每个值假设为每个木板
用for循环遍历，声明移动指针left和最右边的木板right-------->（left和right指数组下标）
假设当前height[i]为最左边的木板，若height[i]等于0或者小于等于其左边最长木板，跳过continue
确定好左边的木板height[i]后，确定最右边的木板right，
right越接近右边越优先，且height[right]>=height[i]

确定好两块木板height[right]和height[i]后，把他们中间小于height[i]的全部“装水”

接着for循环继续寻找下一块height[i]木板

![未命名文件.png](https://pic.leetcode-cn.com/6b1fe686da6bacaff318b95216159f9a459fcbdad0dac749c9e898a412804640-%E6%9C%AA%E5%91%BD%E5%90%8D%E6%96%87%E4%BB%B6.png)




### 代码

```java
class Solution {
    public int trap(int[] height) {
        int ans = 0,len = height.length,flag_min=0;
        int left = 0,right = 0,index = 0, high = 0;
        for(int i=0;i<len;i++){
            if(height[i]==0||height[i]<=flag_min){
                continue;
            }
            flag_min = Math.max(flag_min,height[i]);
            left = i+1;
            right = len-1;
            while (height[right]<height[i]&&right>left){
                right--;
            }
            while (left<right){
                if(height[left]<height[i]){
                    while (height[left]<height[i]){
                        height[left]++;
                        ans++;
                    }
                }
                left++;
            }
        }
        flag_min = 0;
        for(int i=len-1;i>=0;i--){
            if(height[i]==0||height[i]<=flag_min){
                continue;
            }
            flag_min = Math.max(flag_min,height[i]);
            left = 0;
            right = i-1;
            while (height[left]<height[i]&&right>left){
                left++;
            }
            while (left<right){
                if(height[right]<height[i]){
                    while (height[right]<height[i]){
                        height[right]++;
                        ans++;
                    }
                }
                right--;
            }
        }
        return ans;
    }
}
```