## 思路：
     （1）用left和right指针，开始时都为0：
     （2）right指针向右一直走，过程中记录相同字符的数量，当right遇到下一个不同的字符时就处理一次数据
     将其加入sb。同时将left移到right的位置，count（相同字符的数量）归零，开始下一组计数。
     （3）直到right越界结束。

## 代码：
```java
class Solution {
    public int compress(char[] chars) {
        StringBuffer sb = new StringBuffer();
        int count = 0;
        int left = 0;
        int right = 0;
        while(right < chars.length){
            while(right < chars.length && chars[left] == chars[right]){
                right++;
                count++;
            }
            //这里需要加上等号的原因是因为要append上最后的数据，当right指针超出范围时要处理最后一组字符
            if(right <= chars.length){
                //说明遇到不等的情况了
                sb.append(chars[left]);
                if(count > 1){
                    sb.append(count);
                }
                //记录归零
                count = 0;
                //将left移到下一组字符的开头处，即right所在的位置
                left = right;
            }
        }
        char[] re = sb.toString().toCharArray();
        //将re赋给原数组的，re的长度就是最后的结果
        System.arraycopy(re, 0, chars, 0, re.length);
        return re.length;
    }
}
```
