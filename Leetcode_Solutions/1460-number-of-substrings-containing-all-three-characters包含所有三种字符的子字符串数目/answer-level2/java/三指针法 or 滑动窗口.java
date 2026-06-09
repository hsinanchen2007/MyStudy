作为双周赛第三题，该题还是比较典型的，拿到题目很明显感觉就是滑动窗口的题目，所以先讲滑动窗口。
## 滑动窗口

### 思路
举个例子会更容易理解一些，假如给定字符串 ``str`` = `` "aabbcbacb" ``

* 先右指针向右滑动，直到窗口中出现了a、b、c，停止右指针，在这里也就是在``str.charAt(4)``处停下，此时从该位置开始到末尾，全部都是符合要求的，个数也就是 ``str.length() - right = 9 - 4 = 5``；

* 然后移动左指针 left，每移动左指针一次，就要判断一下该窗口内是否符合要求，如果符合要求，则个数为 ``str.length() - right``；

* 如果不符合要求，也就是窗口内不包含 a 和 b 和 c，此时继续移动 right，重复上述两步即可。

### 代码
```java
class Solution {
    public int numberOfSubstrings(String s) {
        int left = 0;
        int right = 0;
        // 存储窗口内 a、b、c 的数量
        int[] temp = new int[3];
        // 记录符合要求的数量
        int sum = 0;
        temp[s.charAt(right) - 'a']++;
        while(right < s.length()){
            if(temp[0] < 1 || temp[1] < 1 || temp[2] < 1){
                right++;
                if(right == s.length()) break;
                temp[s.charAt(right) - 'a']++;
            }
            else{
                sum = sum + s.length() - right;
                temp[s.charAt(left) - 'a']--;
                left++;
            }
        }
        return sum;  
    }
}
```

## 三指针

### 思路

还是上面的例子，假如给定字符串 ``str`` = `` "aabbcbacb" ``
* 用三个指针记录‘a'，’b'，‘c'的位置，遍历字符串，每次遍历都更新下标最小的字母；

* 在这里当遍历到了 ``str.charAt(4)`` 时，a = 1，b = 3，c = 4,最小的索引值 min 为 1，意思就是加上最小索引值前面的字母也是符合要求的，此时一共符合要求的就是 min + 1。

### 代码

```java
class Solution {
    public int numberOfSubstrings(String s) {
        int a = -1, b = -1, c = -1;
        int sum = 0;
        for(int i = 0;i < s.length();i ++){
            if(s.charAt(i) == 'a') a = i;
            else if(s.charAt(i) == 'b') b = i;
            else c = i;
            if(a != -1 && b != -1 && c != -1){
                sum += Math.min(Math.min(a,b),c)+1;
            }
        }
        return sum;
    }
}
```