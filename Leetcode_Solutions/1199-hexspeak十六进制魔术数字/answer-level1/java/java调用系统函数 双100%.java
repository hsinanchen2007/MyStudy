![image.png](https://pic.leetcode-cn.com/9b786061079d288cc0dc43d8e0e0ad9af55d8c0ce217594313791df0ffaccd6f-image.png)
public static String toHexspeak(String num) {
        String toHexString = Long.toHexString(Long.valueOf(num));
       for (int i=0;i<toHexString.length();i++)
       {
            if (toHexString.charAt(i)>= 50 && toHexString.charAt(i)<=57)
                return "ERROR";
       }
        return toHexString.replaceAll("1", "I").replaceAll("0","O").toUpperCase();
    }

补充：由于可能会越界，一定要用Long不是Interger