### 解题思路
/**
    1.统计大小写出现的次数 在数组中记录
    2.分析每一条记录
        1.为奇数的话 则-1 变成偶数（当为偶数的时候，可以一一对应变成回文）
        2.为偶数的话 则可以直接形成回文
    3.如果最后的长度小于总长度，可以在中心点插上一个值，作为回文的中心
*/

### 代码

```java

class Solution {
    public int longestPalindrome(String s) {
        int count = 0;
        int[] arr = new int[52];//大写+小写
        for(char c : s.toCharArray()){
            //区分大小写
            if(c >= 'a' && c <= 'z') arr[c - 'a']++;
            else arr[c - 'A' + 26]++;
        }

        for(int i : arr){
            //如果出现的次数是奇数个 变成偶数个进行加减
            if(i % 2 == 1) count += i-1;
            else count += i;
        }
        //如果现在已经前后配对好了，需要在中间放置任意一个
        
        return count < s.length()? count +=1 : count;
    }
}
```