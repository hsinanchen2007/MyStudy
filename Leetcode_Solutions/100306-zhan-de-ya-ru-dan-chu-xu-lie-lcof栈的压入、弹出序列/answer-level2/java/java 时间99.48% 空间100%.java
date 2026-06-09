### 解题思路

### 代码

```java
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        //x为pushed数组的指针、y为popped数组的指针、z为tmp数组的指针
        int x=0,y=0,z=0;
        //用于临时存储pushed的数据
        int [] tmp=new int[pushed.length];
        while(y<popped.length){
            //如果x指针已经移到了pushed数组的尾部
            if(x==pushed.length){
                //则只需看popped剩余的数值是否与tmp数组反向遍历的数值一致，不一致则直接返回false
                if(tmp[--z]!=popped[y++]){
                    return false;
                }
                continue;
            }
            if(pushed[x]==popped[y]){
                //如果pushed的x位置的数据恰好等于popped的y位置的数据，则直接将x和y指针后移
                x++;
                y++;
            }else{
                //如果x和y处的值不等
                if(z-1>=0 && tmp[z-1]==popped[y]){
                    //如果tmp数组中有数，且tmp的最末尾的数恰好是popped的y位置的数，那么将z向前移一位，y后移一位
                    z--;
                    y++;
                }else{
                    //如果popped的y位置的数不在tmp的末尾，则将x加入tmp的末尾
                    tmp[z++]=pushed[x++];
                }
            }
        }
        return true;
    }
}
```