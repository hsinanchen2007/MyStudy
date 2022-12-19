### 解题思路
1. solution和guess分别用数组记录他们R、Y、G、B的次数
2. 可能正确f_right = 两数组的相同颜色的较小值 之和
3. 正确right = 字符串对应位置相同的个数
4. 伪正确 = f_right - right

### 代码

```java
class Solution {
    public int[] masterMind(String solution, String guess) {
        int[] s = check(solution);
        int[] g = check(guess);
        int right = 0;
        int f_right = 0;
        for (int i = 0; i < s.length; i++){
            if (solution.charAt(i) == guess.charAt(i)){
                right++;
            }
            f_right += s[i] < g[i] ? s[i] : g[i];
        }
        return new int[]{right, f_right - right};
    }

    //数组从0-3依次代表R、Y、G、B
    public int[] check(String str){
        int[] color = new int[4];
        for (int i = 0; i < color.length; i++){
            char ch = str.charAt(i);
            if (ch == 'R') {
                color[0]++;
                continue;
            }
            if (ch == 'Y'){
                color[1]++;
                continue;
            }
            if (ch == 'G'){
                color[2]++;
                continue;
            }
            if (ch == 'B'){
                color[3]++;
                continue;
            }
        }
        return color;
    }
}
```

