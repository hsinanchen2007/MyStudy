### 解题思路
1.看题目的规则，要得到每个元素的结果 元素 + 元素个数，需要遍历所有的元素 ，时间复杂度 O(N)
2.新的字符串长度要小于原始字符串长度，长度作为条件，每次增加字符串 元素 + 元素个数 ，超出长度直接return
3.元素个数的长度是可变的，因此需要在确定长度的时候，再添加字符串
4.遍历完所有元素后，根据长度条件，返回结果

### 代码

```java
class Solution {
    public String compressString(String S) {
         if (S == null || S.length() == 0){
            return S;
        }
        // 肯定要把所有的元素遍历一遍 时间复杂度 O(N)
        char[] src = S.toCharArray();

        StringBuilder sb = new StringBuilder();
        char pivot = src[0];
        int count = 1;
        // 注意value的长度不固定至少是1位数
        for (int i = 1; i < src.length; i++) {
            if (pivot == src[i]){
                ++count;
            } else {
                sb.append(pivot).append(count);
                if (sb.length() >= src.length){
                    return S;
                }
                pivot = src[i];
                count = 1;
            }
        }
        sb.append(pivot).append(count);

        return sb.length() >= src.length ? S:sb.toString();
    }
}
```