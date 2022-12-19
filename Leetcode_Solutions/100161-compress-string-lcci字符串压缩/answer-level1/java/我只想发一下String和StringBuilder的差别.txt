### 解题思路
![QQ截图20200316213545.jpg](https://pic.leetcode-cn.com/f4cb0d0d3ae664b18ca27af99e860f19ebec35b5b714ad8b3c23fac91c1bf46e-QQ%E6%88%AA%E5%9B%BE20200316213545.jpg)



### 代码

```java
class Solution {
    public String compressString(String S) {
        if(S.length() < 3){
            return S;
        }
        int size = 1;
        StringBuilder result = new StringBuilder();
        for (int i = 0, j = 1; i < S.length(); i++, j++) {
            char c1 = S.charAt(i);
            char c2 = S.charAt(j);
            if(c1 == c2){
                size++;
                if(j == S.length() - 1){
                    result.append(c1);
                    result.append(size);
                    break;
                }
            }else{
                result.append(c1);
                result.append(size);
                size = 1;
                if(j == S.length() - 1){
                    result.append(c2);
                    result.append(1);
                    break;
                }
            }
        }
        return S.length() < result.length() ? S : result.toString();
    }
}
```