### 解题思路
此处撰写解题思路
当两点之间的距离不等于三点的距离之和
### 代码

```java
class Solution {
    public boolean isBoomerang(int[][] points) {
       double count,len,fun;
       count=(points[0][0]-points[1][0])*(points[0][0]-points[1][0])+
       (points[0][1]-points[1][1])*(points[0][1]-points[1][1]);
       len=(points[0][0]-points[2][0])*(points[0][0]-points[2][0])+
       (points[0][1]-points[2][1])*(points[0][1]-points[2][1]);
       fun=(points[2][0]-points[1][0])*(points[2][0]-points[1][0])+
       (points[2][1]-points[1][1])*(points[2][1]-points[1][1]);
       count=(double)Math.sqrt(count);
        len=(double)Math.sqrt(len);
         fun=(double)Math.sqrt(fun);
       if(count+len==fun||count+fun==len||len+fun==count)
       return false;
       return true;
    }
}
```