```
class Solution {
    public int compareVersion(String version1, String version2) {
        // 思路，从左到右一个一个版本号对比
        int len1 = version1.length();
        int len2 = version2.length();

        int k = 0;
        int curVersion1StartIndex = 0;
        int curVersion1EndIndex = 0;
        int curVersion2StartIndex = 0;
        int curVersion2EndIndex = 0;
        while (curVersion1EndIndex < len1 || curVersion2EndIndex < len2){
            // 先找V1的最左边的版本号
            int curVersion1Num = 0;
            for (; curVersion1EndIndex < len1; curVersion1EndIndex++){
                if (version1.charAt(curVersion1EndIndex) == '.') break;
            }
            if (curVersion1EndIndex != curVersion1StartIndex){ // 如果开始和结束的位置不相等，说明当前可以截取字段，如果相等，就默认用0替代，用于后面的比较
                curVersion1Num = Integer.valueOf(version1.substring(curVersion1StartIndex, curVersion1EndIndex));
            }

            // 再找V2的最左边的版本号
            int curVersion2Num = 0;
            for (; curVersion2EndIndex < len2; curVersion2EndIndex++){
                if (version2.charAt(curVersion2EndIndex) == '.') break;
            }
            if (curVersion2EndIndex != curVersion2StartIndex){
                curVersion2Num = Integer.valueOf(version2.substring(curVersion2StartIndex, curVersion2EndIndex));
            }

            if (curVersion1Num > curVersion2Num) return 1;
            if (curVersion1Num < curVersion2Num) return -1;

            curVersion1StartIndex = ++curVersion1EndIndex;
            curVersion2StartIndex = ++curVersion2EndIndex;
        }
        return 0;
    }
}
```
