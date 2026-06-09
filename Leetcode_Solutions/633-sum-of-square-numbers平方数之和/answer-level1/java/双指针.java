### 解题思路
此处撰写解题思路
很简单的代码与思路
两个指针分别指向头尾，头尾指针分别初始化为0和(int)Math.sqrt(c),分别前后移动即可。
### 代码

```java
class Solution {
    public boolean judgeSquareSum(int c) {
        int i=0,j=(int)Math.sqrt(c);
        while(i<=j){
            int sum=i*i+j*j;
            if(sum==c) return true;
            else if(sum<c) i++;
            else j--;
        }
        return false;
        
    }
}
```