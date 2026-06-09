**思路简单，暴力求解一**
```
public static boolean isOneEditDistance(String s, String t) {
        int larger, litter; //定义变量
        char[] arr1, arr2; //定义字符数组

        if (s.length() > t.length()) { //初始化变量信息
            larger = s.length();
            litter = t.length();
            arr1 = s.toCharArray();
            arr2 = t.toCharArray();
        } else {
            larger = t.length();
            litter = s.length();
            arr1 = t.toCharArray();
            arr2 = s.toCharArray();
        }

        int number = larger - litter; //定义参数变量
        if (s.equals(t) || number > 1) {
            return false;
        }
        if (s.equalsIgnoreCase(t) || (number == 1 && s.contains(t) || t.contains(s))) {
            return true;
        }

        int temp = 0;
        if (number == 0) { //跳过不同字符，两个字符串相等
            StringBuilder sbArr1 = new StringBuilder();
            StringBuilder sbArr2 = new StringBuilder();
            boolean flag = true;
            while (temp <= larger - 1) {
                if (arr1[temp] != arr2[temp] && flag) {
                    temp++;
                    flag = false;
                    continue;
                } else {
                    sbArr1.append(arr1[temp]);
                    sbArr2.append(arr2[temp]);
                    temp++;
                }
            }
            if (sbArr1.toString().length() > 0 && sbArr1.toString().equals(sbArr2.toString())) {
                return true;
            }
        } else if (number == 1) { //去掉多余字符，两个字符串相等
            StringBuilder sb = new StringBuilder();
            boolean flag = true;
            int num = 0;
            while (temp < larger - 1) {
                if (arr1[temp] != arr2[temp] && flag) {
                    temp++;
                    sb.append(arr1[temp]);
                    flag = false;
                    num = 1;
                    continue;
                } else {
                    sb.append(arr1[temp + num]);
                    temp++;
                }
            }
            if (sb.toString().equals(s) || sb.toString().equals(t)) {
                return true;
            }
        } else {
            return false;
        }
        return false;
    }
```
**思路简单，暴力求解二**

```
public static boolean isOneEditDistance(String s, String t) {
        int larger, litter; //定义变量
        char[] arr1, arr2; //定义字符数组
        if (s.length() > t.length()) { //初始化变量信息
            larger = s.length();
            litter = t.length();
            arr1 = s.toCharArray();
            arr2 = t.toCharArray();
        } else {
            larger = t.length();
            litter = s.length();
            arr1 = t.toCharArray();
            arr2 = s.toCharArray();
        }

        int number = larger - litter; //定义参数变量
        if (s.equals(t) || number > 1) {
            return false;
        }
        if (s.equalsIgnoreCase(t) || (number == 1 && s.contains(t) || t.contains(s))) {
            return true;
        }

        List<Integer> list = new ArrayList<>();
        int j = 0;
        for (int i = 0; i < arr1.length; i++) {
            if (number == 0 && arr1[i] == arr2[i]) {
                list.add(i);
                continue;
            }
            if (number == 1 && arr1[i] == arr2[j]) {
                list.add(i);
                j++;
                continue;
            }
        }

        int standard = list.size();
        int start = arr1.length;
        int end = arr2.length;
        if ((standard == (start - 1) && standard == (end - 1)) || (standard == start && standard == (end - 1)) || (standard == (start - 1) && standard == end)) {
            return true;
        }
        return false;
    }
```
