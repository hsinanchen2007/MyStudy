### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/992b2424fcadd657f947fde914ddad9660285f254390d44c2d26f275c22c510d-image.png)

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        char[] copy = Integer.toString(num).toCharArray();
        for(int i = 0;i < copy.length;i++){
            if(copy[i] == '6'){
                copy[i] = '9';
                return Integer.parseInt(new String(copy));
            }
        }
        return num;
    }
}
```