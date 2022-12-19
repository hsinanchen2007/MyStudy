### 解题思路
效果还不错
![QQ浏览器截图20200311165840.png](https://pic.leetcode-cn.com/3208100314967b02a07903539546d1419d44ebdb65df8d6f66660ccf7d34e2a9-QQ%E6%B5%8F%E8%A7%88%E5%99%A8%E6%88%AA%E5%9B%BE20200311165840.png)

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int len = A.length;
        int count=0,s=0,sum=0;
        for(int i = 0;i < len;i++){
            sum += A[i];
        }
        if(sum%3==0){
            for(int j = 0;j<len;j++){
            s += A[j];
            if(s == sum/3){
                s = 0;
                count++;
                if(count == 3){
                    return true;
                    }
                }
            }
        }
    return false;
    }
}
```