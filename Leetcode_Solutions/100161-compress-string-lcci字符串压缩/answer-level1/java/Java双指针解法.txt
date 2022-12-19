![image.png](https://pic.leetcode-cn.com/fe2eb7e8af13f247ede6c5e77af43f0b10fd016edf75a639f68f90f2e5921688-image.png)

### 解题思路
一开始是想直接遍历S，判断后面一个字符是否与前一个相等，但是这样还要单独处理边界情况，写起来就不是很简洁，所以又想到了用双指针，一气呵成

### 代码

```java
class Solution {
    public String compressString(String S) {
        StringBuilder sb = new StringBuilder();
        char[] arr = S.toCharArray();
        int l = 0, r = 0, count = 0;
        while(l<S.length()){
            while(r<S.length() && arr[l]==arr[r]){
                r++;
                count++;
            }
            sb.append(arr[l]);
            sb.append(count);
            l = r;
            count = 0;
        }
        return sb.length()<S.length()?sb.toString():S;
    }
}
```