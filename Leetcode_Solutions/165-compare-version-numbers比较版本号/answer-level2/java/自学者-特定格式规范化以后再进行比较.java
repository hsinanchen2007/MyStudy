### 解题思路
* 特定格式规范化以后再进行比较

### 代码

```java []
// 方案一、传统比较法
class Solution {
    private static String normalize(String version) {
        String result = version;
        String[] split = result.split("\\.");
        List<String> strings = new ArrayList<>(4);
        int subCount = 4;
        for (int i = 0; i < subCount; i++) {
            if (i<split.length) {
                if (split[i].length() > 1){
                   split[i] = split[i].replaceAll("^0+","");   
                }
                strings.add(split[i]);
            } else {
                strings.add("0");
            }

        }
        return String.join(".",strings);
    }
    public int compareVersion(String version1, String version2) {
        version1 = normalize(version1);
        version2 = normalize(version2);
        //System.out.printf("%s\n%s\n",version1,version2);
        if(version1.equals(version2)) {
            return 0;
        }
        String[] v1Seg = version1.split("\\."); 
        String[] v2Seg = version2.split("\\."); 
        for (int i = 0; i < 4; i++) {
            if ( Integer.valueOf(v1Seg[i]) > Integer.valueOf(v2Seg[i]) ) {
                return 1;
            } else  if ( Integer.valueOf(v1Seg[i]) == Integer.valueOf(v2Seg[i]) ) {
                continue;
            } else {
                break;
            }
        }
       
        return -1;
    }
}
```

```java []
// 方案二、刷题学习简洁优雅的代码
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1Seg = version1.split("\\."); 
        String[] v2Seg = version2.split("\\."); 
        for (int i = 0; i < Math.max(v1Seg.length,v2Seg.length); i++) {
           int num1 = i < v1Seg.length ? Integer.valueOf(v1Seg[i]) : 0;
           int num2 = i < v2Seg.length ? Integer.valueOf(v2Seg[i]) : 0;
            if(num1 != num2) {
                return num1 > num2 ? 1 : -1;
            }
        }
        return 0;
    }
}
```