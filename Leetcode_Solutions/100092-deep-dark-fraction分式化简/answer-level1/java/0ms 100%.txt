### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] fraction(int[] cont) {
        int [] num = new int[2];
        num[1] = cont[cont.length - 1];
        num[0] = 1;
        for (int i = cont.length - 2;i >= 0; i--)
            num = helper(cont[i],num);

        return new int[]{num[1],num[0]};
    }
    private int[] helper(int num,int [] fraction){
        num = num * fraction[1];
        fraction[0] += num;
        return new int[]{fraction[1],fraction[0]};
    }
}
```