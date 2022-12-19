一开始觉得和29题两数相除思路很像，使用乘以2加速的方法来做。PS：使用long型技巧，防止数据溢出。

耗时比二分查找差，也不妨是一种行得通的方案。
![image.png](https://pic.leetcode-cn.com/a4c255e0d8f44ab1b33db309f4219f44b19e2b6b0c62a079d0842f5b758b55fd-image.png)

```
class Solution {
    public int mySqrt(int x) {
        long temp=1,i=1;
        
        while(temp<x){
            i=i*2;
            temp=i*i;
            if(temp!=(int)temp) break;
        }
    
        i/=2;
        while((++i)*(i)<=x);
        
        return (int)--i;
        
    }
}
```

