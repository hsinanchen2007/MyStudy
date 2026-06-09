### 解题思路
暴力求解

### 代码

```java
class Solution {
    public List<Integer> selfDividingNumbers(int left, int right) {
         List<Integer> list = new ArrayList<>();

        for (int i = left; i <= right; i++) {
            int temp = i;
            boolean b = true;
            while(temp>0){
                int rex = temp%10;
                //不允许包括0
                if(rex == 0 || i%rex!=0){
                    b = false;
                    break;
                }
                temp /= 10;
            }
            if(b){
                list.add(i);
            }
        }
        return list;
    }
}
```