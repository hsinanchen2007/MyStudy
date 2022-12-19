执行结果：
通过
显示详情
执行用时 :
2 ms
, 在所有 Java 提交中击败了
93.24%
的用户
内存消耗 :
34.2 MB
, 在所有 Java 提交中击败了
33.34%
的用户
```
class Solution {
    public int compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");
        int l1 = v1.length;
        int l2 = v2.length;
        int min=Math.min(l1,l2);
        for(int i=0; i<min; i++){
            int i1 = Integer.valueOf(v1[i]);
            int i2 = Integer.valueOf(v2[i]);
            if(i1<i2){
                return -1;
            }else if(i1>i2){
                return 1;
            }
        }
        if(l1>l2){
            for(int i=min; i<l1; i++){
                if(Integer.valueOf(v1[i])!=0){
                    return 1;
                }
            }
            return 0;
        }else if(l1<l2){
            for(int i=min; i<l2; i++){
                if(Integer.valueOf(v2[i])!=0){
                    return -1;
                }
            }
            return 0;
        }else{
            return 0;
        }
    }
}
```
