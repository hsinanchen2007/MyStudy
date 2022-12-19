### 解题思路
这个很粗糙，就是直接递归，还需要些优化和剪枝，但是就很好读
### 代码

```java
// package com.leetcode.practices.examQuestions.restoreIpAddresses;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Solution {
    List<String> ipList;

    String originalS;

    HashMap<String, Boolean> visited;

    public List<String> restoreIpAddresses(String s) {
        ipList = new ArrayList<>();
        originalS = s;
        visited = new HashMap<>();

        vaildIpSpilt(0, 4, new StringBuilder());

        return ipList;
    }

    boolean vaildIpSpilt(int start, int devideNum, StringBuilder sb) {

        String key = sb.toString() + "_" + devideNum;
        if (visited.containsKey(key)) {
            return visited.get(key);
        }

        if (devideNum == 1) {
            if (vaildIp(originalS.substring(start))) {
                sb.append(originalS.substring(start));
                ipList.add(sb.toString());
                return true;
            }
            return false;
        }

        boolean oneSplit = false;
        boolean twoSplit = false;
        boolean threeSplit = false;
        
        if (vaildIp(safeSubString(originalS, start, start + 1))) {
            StringBuilder sb1 = new StringBuilder(sb.toString());
            sb1.append(originalS, start, start + 1);
            sb1.append(".");
            oneSplit = vaildIpSpilt(start + 1, devideNum - 1, sb1);
        }

        if (vaildIp(safeSubString(originalS, start, start + 2))) {
            StringBuilder sb2 = new StringBuilder(sb.toString());
            sb2.append(originalS, start, start + 2);
            sb2.append(".");
            twoSplit = vaildIpSpilt(start + 2, devideNum - 1, sb2);
        }

        if (vaildIp(safeSubString(originalS, start, start + 3))) {
            StringBuilder sb3 = new StringBuilder(sb.toString());
            sb3.append(originalS, start, start + 3);
            sb3.append(".");
            threeSplit = vaildIpSpilt(start + 3, devideNum - 1, sb3);
        }

        if (oneSplit || twoSplit || threeSplit) {
            visited.put(key, true);
            return true;
        }
        visited.put(key, false);
        return false;

    }

    boolean vaildIp(String s) {
        if (s.length() > 9 || s.length() == 0 || (s.startsWith("0") && !s.equals("0"))) {
            return false;
        }
        int value = Integer.parseInt(s);
        return value >= 0 && value <= 255;
    }

    String safeSubString(String str, int s, int e) {
        if (s < 0 || e > str.length() - 1) {
            return "";
        }
        return str.substring(s, e);
    }
}

```