### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String toHex(int num) {
        if(num==0) return "0";
        StringBuilder sb=new StringBuilder();
        char[] arr="0123456789abcdef".toCharArray();
        while(num!=0){
            int temp=num&15;
            sb.insert(0,arr[temp]);
            num>>>=4;
        }
        return sb.toString();
    }
}
```