
![image.png](https://pic.leetcode-cn.com/d8c67749f3a55de98f6c4958922a59b938def93289ed459587915554fe10edd4-image.png)
pkg是钱包

```
class Solution {
    public boolean lemonadeChange(int[] bills) {
        if (bills[0] != 5) {return false;}
        if (bills.length == 0) {return true;}
        HashMap<Integer, Integer> pkg = new HashMap<>();
        pkg.put(5,0);
        pkg.put(10,0);

        for (int bill : bills) {
            if (bill == 5) {
                pkg.put(5, pkg.get(5) + 1);
            }
            if (bill == 10) {
                if (pkg.get(5) > 0) {
                    pkg.put(5, pkg.get(5) - 1);
                    pkg.put(10, pkg.get(10) + 1);
                } else {
                    return false;
                }
            }
            if (bill == 20) {
                if (pkg.get(10) > 0) {
                    if (pkg.get(5) > 0) {
                        pkg.put(5, pkg.get(5) - 1);
                        pkg.put(10, pkg.get(10) - 1);
                    } else {
                        return false;
                    }
                } else {
                    if (pkg.get(5) >= 3) {
                        pkg.put(5, pkg.get(5) - 3);
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
```
