![TIM截图20200323195050.jpg](https://pic.leetcode-cn.com/ff5153a270d896ec9b5a11054abbc7458d91f2d727b184f6cbf6a6bba099b7a5-TIM%E6%88%AA%E5%9B%BE20200323195050.jpg)

### 解题思路
构造一个位数为n的字符数组，把数组中的所有元素全部设为'9'，然后字符数组转字符串再转整数，再依次填充整数数组   

### 代码

```java
class Solution {
    public int[] printNumbers(int n) {
        if(n <= 0)
            return null;
        
        char[] chars = new char[n];
        for(int i = 0;i < n;++i)
            chars[i] = '9';
        String str = String.valueOf(chars);
        int maxNum = Integer.parseInt(str);

        int[] arr = new int[maxNum];
        for(int i = 0;i < maxNum;++i)
            arr[i] = i + 1;
        return arr;
    }
}
```