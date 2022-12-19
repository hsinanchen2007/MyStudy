### 解题思路
此处撰写解题思路
遍歷，轉化爲字符串獲取長度
### 代码

```java
class Solution {
 public int findNumbers(int[] nums) {
        int num=0;
        for (int i : nums) {
            int length = String.valueOf(i).length();
            if (length%2==0){
                num++;
            }
        }
        return num;
    }
}
```