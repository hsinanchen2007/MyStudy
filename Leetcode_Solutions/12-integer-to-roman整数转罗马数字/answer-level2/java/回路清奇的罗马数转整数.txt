### 解题思路
看了大佬们的解题思路，发现我真是菜鸡啊，打败了5%的用户
流下了不学无术的眼泪
先求数据位数，再转成String，new 一个HashMap存放罗马数与整数的对应关系，最后依次从最高位取对应数值，根据0-9的情况进行append

### 代码

```java
class Solution {
    public String intToRoman(int num) {
        // n 为输入数据位数+1
        int n = 1;
        if (num > 999){
            n = 4;
        }else if (num >99){
            n = 3;
        }else if (num > 9){
            n = 2;
        }
        String s = num + "";
        StringBuffer ans = new StringBuffer();
        // 为什么是Double呢，因为Math.pow()返回的是double，不想转来转去的
        HashMap<Double, String> map = new HashMap<>(){};
        map.put(1.0, "I");
        map.put(5.0, "V");
        map.put(10.0, "X");
        map.put(50.0, "L");
        map.put(100.0, "C");
        map.put(500.0, "D");
        map.put(1000.0, "M");

        // 就分情况进行append
        for (int i = 1; i <= n; i++) {
            int val = Integer.parseInt(s.charAt(i-1)+"");
            if (val>=5){
                if (val==9){
                    ans.append(map.get(Math.pow(10, n - i))).append(map.get(Math.pow(10, n - i + 1)));
                }else {
                    ans.append(map.get(5 * Math.pow(10, n - i)));
                    for (int j = 0; j < val - 5; j++) {
                        ans.append(map.get(Math.pow(10, n - i)));
                    }
                }
            }else {
                if (val==4){
                    ans.append(map.get(Math.pow(10, n - i))).append(map.get(5 * Math.pow(10, n - i)));
                }else {
                    for (int j = 0; j < val; j++) {
                        ans.append(map.get(Math.pow(10, n - i)));
                    }
                }
            }
        }
        return ans.toString();
    }
}
```