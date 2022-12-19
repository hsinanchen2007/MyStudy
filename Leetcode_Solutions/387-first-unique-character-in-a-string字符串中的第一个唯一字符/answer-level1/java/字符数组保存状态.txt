### 解题思路
![546A34E8-44E4-4170-88A8-3E615A2836CA.png](https://pic.leetcode-cn.com/c9fd4eda574d765d41adcb2ce443cfbfd01ea5fbb1e0288156d5bb159a941927-546A34E8-44E4-4170-88A8-3E615A2836CA.png)
设置一个26位的数组
1，赋初值为-1，表示字符串s中没有此字符
2，如果出现重复字符，数组值为0
3，不出现重复字符且为唯一字符，值为对应字符的索引值+1

最后，遍历26位的数组，找出最小的索引值即可

p.s:总觉得我写的这个代码优化余地很大

### 代码

```java
class Solution {
    public int firstUniqChar(String s) {
        if (s.length() == 0) {
            return -1;
        }
        //字符数组 设置为26个字符 value记录索引值+1 如果有重复的值，value为0
        int[] arr = new int[26];

        //赋初值为-1 表示未赋值过 0 表示重复的值 i+1 表示无重复的值
        for (int i = 0; i < 26; i++) {
            arr[i] = -1;
        }

        //循环字符串
        for (int i = 0; i < s.length(); i++) {
            if (arr[s.charAt(i)-'a'] > 0) {//有重复值
                arr[s.charAt(i)-'a'] = 0;
            } else if (arr[s.charAt(i)-'a'] == -1) {//未赋值过
                arr[s.charAt(i)-'a'] = i+1;//对应索引值加1
            }
        }

        //找出索引最低的值
        int index = Integer.MAX_VALUE;
        for (int i = 0; i < 26; i++) {
           if (arr[i] > 0) {
               index = Math.min(index, arr[i] - 1);
           } 
        }

        return (index == Integer.MAX_VALUE) ? -1 : index;
    }
}
```