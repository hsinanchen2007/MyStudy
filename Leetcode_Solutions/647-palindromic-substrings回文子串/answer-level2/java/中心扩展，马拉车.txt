### 解题思路
常见的思路是，遍历数组，对每个回文串中心位置检测并计数
马拉车算法维护最长回文串，
在这个最长串里面的中心是左右对称的，所以可以利用这一点去重！
算法优化的关键之一就是去重。

### 代码

```java
class Solution {
    public int countSubstrings(String s) {
        int count = s.length();
        for(int i = 0;i < s.length()-1; i++){
            count += count(s,i,i);
            if(s.charAt(i) == s.charAt(i+1)){
                count += (1+count(s,i,i+1));
            }
        }
        return count;
    }
    //中心扩展法
    private int count(String s,int i,int j){
        int count = 0;
        while(i >0 && j < s.length()-1 && (s.charAt(--i) == s.charAt(++j))){
            count++;
        }
        return count;
    }
}
```

### 马拉车
预处理：首位添加$，每个字符之间插入#；
这样原回文串的长度len为现在回文串半径r-1，
且原回文串起始位置为现中心位置center减半径再除以2.

然后维护一个中心为i的最长回文串长度的数组，并记录右上界；
每当下一个i落在之前中心的最长串内，先比较对称位置j的最长串和右边界到i的距离；
若小于，则确定当前i的最长串，若大于，则需要比较越界的部分，然后更新中心和右边界。

### 代码

```java
class Solution {
    public int countSubstrings(String s) {
        char[] rebuild = new char[2 * s.length() + 3];
        rebuild[0] = '$';
        rebuild[1] = '#';
        rebuild[rebuild.length - 1] = '@';
        int p = 2;
        for (char c: s.toCharArray()) {
            rebuild[p++] = c;
            rebuild[p++] = '#';
        }

        int[] max = new int[rebuild.length];
        int center = 0, right = 0;
        for (int i = 1; i < max.length - 1; ++i) {
            if (i < right)
                //利用对称和之前的max值去重
                max[i] = Math.min(right - i, max[2 * center - i]);
            while (rebuild[i + max[i] + 1] == rebuild[i - max[i] - 1])
                max[i]++;
            if (i + max[i] > right) {
                center = i;
                right = i + max[i];
            }
        }
        int count = 0;
        for (int m: max) count += (m + 1) / 2;
        return count;
    }
}
```