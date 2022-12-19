### 解题思路
先判断字符串的长度
然后将字符串转化为数组
然后 运用双指针去写m，就很好写了

### 代码

```java
class Solution {
    public String compressString(String S) {
        int len = S.length();
        if(len<1){
            return S;
        }
        StringBuilder sb = new StringBuilder();
        char[] arr = S.toCharArray();
        int pre = 0;
        int next = 0;
        int count = 0;
        while(pre<len){
            while(next<len&&arr[pre]==arr[next]){
                next++;
                count++;
            }
            sb.append(arr[pre]);
            sb.append(count);
            pre = next;
            count=0;
        }
        return sb.length()<len?sb.toString():S;
    }
}
```