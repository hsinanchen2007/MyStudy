哈希思想，博大精深。
一个128长度的数组解决一切。
时间复杂度$O(n)$
空间复杂度$O(1)$
```java
public boolean CheckPermutation(String s1, String s2) {
    int [] arr = new int[128];
    if (s1.length() != s2.length()) {
        return false;
    }
    char[] arr1 = s1.toCharArray();
    char[] arr2 = s2.toCharArray();
    for (int i = 0, len = arr1.length; i < len; ++i) {
        arr[arr1[i]]++;
        arr[arr2[i]]--;
    }
    for (int item : arr) {
        if (item != 0) {
            return false;
        }
    }
    return true;
}
```
结果还行：
![image.png](https://pic.leetcode-cn.com/ffbb130f091b4b10e3cc7dee4c985a8bd67e3f8b13396a2b51d54cba78d3ccdc-image.png)


