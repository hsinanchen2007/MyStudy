![image.png](https://pic.leetcode-cn.com/ffb4e964ade5f9f16fe6568ef74e19aae445be186db0c80e142153a7a51cd0b7-image.png)

### 解题思路
字符串中的每个字符，必然能找到对应的ASCII码，利用ASCII码表进行减法计算。
1、将字符串转换成字符数组；
2、循环码表，从小到大的顺序
3、如果找到和码表起始字符相等的字符，记录为命中最小值；
4、如果在接下来的循环中，还能命中最小值，说明，存在重复；
5、如果该轮循环没有找到与码表最小值相等的字符，则进入下轮循环；


### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        char[] chars = astr.toCharArray();
        for (int i = 63; i < 122; i++) {
            int tmp = 0;
            boolean eq = false;
            for (char aChar : chars) {
                tmp = aChar - i;
                if (tmp == 0 && eq){
                    return false;
                }
                if (tmp == 0 ) {
                    eq = true;
                }
            }
        }
        return true;
    }
}
```