```java
class Solution {
    public String validIPAddress(String IP) {
        String[] ipv4 = IP.split("\\.", -1);
        String[] ipv6 = IP.split("\\:", -1);
        if (IP.chars().filter(ch -> ch == '.').count() == 3) {
            for (String s : ipv4) if (isIPv4(s)) continue; else return "Neither";
            return "IPv4";
        }

        if (IP.chars().filter(ch -> ch == ':').count() == 7) {
            for (String s: ipv6) if (isIPv6(s)) continue; else return "Neither";
            return "IPv6";
        }
        return "Neither";
    }

    boolean isIPv4(String s) {
        try {
            if (String.valueOf(Integer.valueOf(s)).equals(s) && Integer.parseInt(s) >= 0 && Integer.parseInt(s) <= 255) return true;
            else return false;
        } catch(Exception e) {
            return false;
        }

    }

    boolean isIPv6(String s) {
        try {
            if (s.length() > 4) return false;
            if (Integer.parseInt(s, 16) >= 0 && s.charAt(0) != '-') {
                return true;
            }
            return false;
        } catch(Exception e) {
            return false;
        }

    }
}
```