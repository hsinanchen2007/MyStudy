### 解题思路
直接对最大数进行开根（但是我在这里有一个疑问 在Leecode里面对数字进行开根号 可以是int类型  但是在idea中必须要是double  不然会报错）
在对左边进行依次搜索
先用数字小的做判断
再用+2的做判断

### 代码

```java
class Solution {
    public int[] closestDivisors(int num) {
        int posNum1 = num + 1;
        int posNum2 = num + 2;
        int a = (int)Math.sqrt(posNum2);
        for(int i = a ; i >= 1 ; i --){
            if(posNum1 % i == 0){
                return new int[]{i , posNum1 / i};
            }
            else if(posNum2 % i == 0){
                return new int[]{i , posNum2 / i};
            }
        }
        return new int[]{};
    }
}
```