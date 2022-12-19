### 注意点&原理 ###
- 字符集为 ASCII 128 中存放每个字符最后出现的位置+1
- j是窗口的右边不断增加
- i是窗口的左边，
- 如果碰到相同字符就会的到上一次位置，相减得到区间就没有重复
- 如果是新的字母，就会小于上一个相同字符，i值就会不变，但是j值会增加所以最长字符串就会加一
- `index[s.charAt(j)] = j + 1;` 这里加一，头尾重复，这是将头位置由重复元素向前一位

### 图解 ###
![A20200220001.png](https://pic.leetcode-cn.com/75de4ed8e00ae72620cebe259ae931ccc1897ceacb0871fa28258d4c0b1c8539-A20200220001.png)


### 代码 ###
```
int n = s.length(), ans = 0;
int[] index = new int[128]; // current index of character
// try to extend the range [i, j]
for (int j = 0, i = 0; j < n; j++) {
    //i 记录左边的位置 j 记录右边的位置 j-1+1 长度
    i = Math.max(index[s.charAt(j)], i); //如果是新的就不会变
    ans = Math.max(ans, j - i + 1);
    index[s.charAt(j)] = j + 1;
}
return ans;
```