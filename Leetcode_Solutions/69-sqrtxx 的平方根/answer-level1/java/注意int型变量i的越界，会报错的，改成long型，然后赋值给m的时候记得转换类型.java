### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        long i=1;
        int m=0;
        if(x==0){
            return 0;
        }
        else{
            while(i>0){
                if(i*i<=x&&(i+1)*(i+1)>x){
                    m =(int)i;
                    break;   
                }
                else{
                    i=i+1;
                }
            }
        }
    return m;
    }
        

    
}
```