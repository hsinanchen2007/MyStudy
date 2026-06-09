### 解题思路
![QQ截图20200305145447.png](https://pic.leetcode-cn.com/33d386d1dcb661fb0e8d00fac022890fc8ea13840ec619df51d7436ecf075d8f-QQ%E6%88%AA%E5%9B%BE20200305145447.png)

就暴力，你怎么说？
### 代码

```java
class Solution {
    public int[] getNoZeroIntegers(int n) {
         for(int a=1;a<n;a++){
            int b=n-a;
            if(!String.valueOf(b).contains("0") && !String.valueOf(a).contains("0")){
                return new int[] {a,b};
            }
        }
        return null;
    }
}
```