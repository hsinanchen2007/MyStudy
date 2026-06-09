### 解题思路
此处撰写解题思路

### 代码

```java
// 双指针
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        //s.length是针对java中数组的，length是数组的一个属性，用来表示数组的长度
        // s.length()则是字符串的一个方法，用来返回字符串的长度的
        int left = 0,right = 0;
        boolean[] used = new boolean[128];
        int max = 0;
        if(s == null || s.length() == 0) return 0;//当然有区别  
// str=null 说明str没有指向任何对象   阳痿和太监还是不一样的，虽然都是不能
// 而str长度为零时str肯定不为null的，此时str指向一个长度为零的字符串
// String s1="",s2=null;
// s1.toString();//这个不报错
// s2.toString();//这个报错 
//ASCII码表一共有128个值，除去值为0的一个127个值，int[] cnt;这个数组共有127个int型内存，数组中每个元素代表每个字符出现的个数，for循环对字符串进行操作，每个字符都对应一个ASCII码值，比如字符a的ASCII码值为97，那么a每出现了一次，cnt['a']++也就是cnt[97]++。
//字符型在内存中存储是用的ASCII码值，所以字符可以直接用来索引
        while(right < n){
            if(used[s.charAt(right)] == false){
                used[s.charAt(right)] = true;
                right++;
        }else {//也就是为 true  碰到已经访问过的
                max = Math.max(max, right - left);
        while(left < right && s.charAt(right) != s.charAt(left)){
                used[s.charAt(left)] = false; 
                left++;//剔除之前的字符，，当找到相同的字符时退出
        }
        left++;
        right++;
     }
    }//这里 while循环结束，把退出循环的当前的结果计算进去
    max = Math.max(max,right - left);
    return max;
    }
}
```