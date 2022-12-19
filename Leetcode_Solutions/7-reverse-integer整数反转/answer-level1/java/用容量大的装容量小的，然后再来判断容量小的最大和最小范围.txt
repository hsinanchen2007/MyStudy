### 解题思路
用一个long类型的存储反转后的数据，然后反转后的数据如果不在int类型的范围，则说明超出

### 代码

```java
class Solution {
    public static int reverse(int x) {
        long num = 0;
        while(x !=0){
            int shang = x/10;
            int yushu = x%10;
            num = yushu+num*10;
			x = shang;
			//System.out.println(x+"==="+yushu+"=="+num);
            if(num>Integer.MAX_VALUE ||num<Integer.MIN_VALUE){
                return 0;
            }
        }
        return (new Long(num)).intValue();
    }
}
```