设立res[0],res[1]表示分子分母，从尾部开始往前遍历cont

```java
class Solution {
    public int[] fraction(int[] cont) {
        int[] res = {0,1};
        int i = cont.length-1;
        for (; i>0;i--){
            int tmp = res[1];
            res[1] = res[0]+cont[i]*res[1];
            res[0] = tmp;
        }
        res[0] = cont[i]*res[1]+res[0];
        return res;
    }
}

```