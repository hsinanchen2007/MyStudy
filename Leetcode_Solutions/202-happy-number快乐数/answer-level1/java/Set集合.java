### 解题思路
set集合保存每一步的值
如果找到1 即找到快乐数 返回true
否则，在集合中找到了已经存在的值，说明存在循环，永远不可能是快乐数，返回false

### 代码

```java
class Solution {
    public boolean isHappy(int n) {
        //set表法
        Set<Integer> set = new HashSet();
        //把初始值放进去
        set.add(n);

        //bad-case
        if (n == 0) {
            return false;
        }

        while (n > 0) {
           String nStr = String.valueOf(n); 
           //重新赋值
           n = 0; 
           for (int i = 0; i < nStr.length(); i++) {
               //System.out.println((nStr.charAt(i) - '0'));
               n += (nStr.charAt(i) - '0') * (nStr.charAt(i) - '0');
           }
           //System.out.println(n);
           if (n == 1) {
               return true;
           }
           if (set.contains(n)) {
               return false;
           } else {
               set.add(n);
           }
        }

        return false;
    }
}
```