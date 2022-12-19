核心判断逻辑都是去比较str[n]和str[n+1]的大小
解法就是不停地比较，然后把剩下的字符串再递归。

```
    private static HashMap<Character, Integer> map = new HashMap<>();

    public static int romanToInt(String s) {
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);

        return counting(s, 0);

    }

    private static int counting(String s, int sum) {
        if (s == null || s.length() == 0)
            return sum;
        if (s.length() == 1) {
            return sum + map.get(s.charAt(0));
        }

        if (map.get(s.charAt(0)) < map.get(s.charAt(1))) {
            return sum + map.get(s.charAt(1)) - map.get(s.charAt(0)) + counting(s.substring(2), sum);
        } else {
            return sum + map.get(s.charAt(0)) + counting(s.substring(1), sum);
        }
    }
```
