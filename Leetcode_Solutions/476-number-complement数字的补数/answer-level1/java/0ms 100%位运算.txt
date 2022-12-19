### 解题思路
不能直接用~因为32位前面补0了，取反前面不想管的位也会取反。
shift求出来有用的位数，
去完反后先左移把没用的置0，再右移恢复

### 代码

```java
class Solution {
    public int findComplement(int num) {
        int shift=0;
        int num1=num;
        while(num1!=0){
            num1=num1>>1;
            shift++;
        }
        return ((~num)<<(32-shift))>>(32-shift);
    }
}
```