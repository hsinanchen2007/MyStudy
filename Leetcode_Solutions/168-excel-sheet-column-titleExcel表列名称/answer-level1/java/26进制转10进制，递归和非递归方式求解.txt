### 解题思路
使用碾转相除法转换进制
和使用递归来转换进制


### 代码

```java
//非递归方式
class Solution {
    StringBuilder sb = new StringBuilder();
    public String convertToTitle(int n) {
        while (n != 0) {
            sb.append((char)(((n - 1) % 26)+'A'));
            n = (n - 1) / 26;
        }
        return sb.reverse().toString();
    }
}

//递归方式
class Solution {
    StringBuilder sb = new StringBuilder();
    public String convertToTitle(int n) {
       
        if (n != 0) {
            convertToTitle((n - 1) / 26);
            sb.append((char) ((n - 1) % 26 + 'A'));
        }
        return sb.toString();
    }
}
```