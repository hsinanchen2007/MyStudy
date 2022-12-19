![屏幕快照 2020-01-15 下午1.34.40.png](https://pic.leetcode-cn.com/724346f9c23c3d85aa772c49984b969f2a31fe7ba72d1e0c188e7155b204e645-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-01-15%20%E4%B8%8B%E5%8D%881.34.40.png)


```
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length(), len2 = version2.length();
        int i = 0, j = 0;
        while(i<len1 || j<len2){
            int v1 = 0, v2 = 0;
            while(i<len1 && version1[i++] != '.'){
                v1 = v1 * 10 + version1[i-1] - '0';
            }
            while(j<len2 && version2[j++] != '.'){
                v2 = v2 * 10 + version2[j-1] - '0';
            }
            if(v1 < v2){
                return -1;
            }
            else if(v1 > v2){
                return 1;
            }
        }
        return 0;
    }
};
```
