## **这种方法应该能够降低字符大于26个的效率，如果字符本身小于26个，效率反而更低。**

```java []
    public int firstUniqChar(String s) {
        int index = -1;
        //反过来，只有26个字符
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int beginIndex = s.indexOf(ch);
            // 从头开始的位置是否等于结束位置，相等说明只有一个，
            if (beginIndex != -1 && beginIndex == s.lastIndexOf(ch)) {
                //取小的，越小代表越前。
                index = (index == -1 || index > beginIndex) ? beginIndex : index;
            }
        }
        return index;
    }
```
执行用时：2 ms


写了个新的题解，融合2种情况：

## **传送门**： [新题解改进版](https://leetcode-cn.com/problems/first-unique-character-in-a-string/solution/tong-guo-zi-fu-chuan-chang-du-fen-cheng-liang-chon/)