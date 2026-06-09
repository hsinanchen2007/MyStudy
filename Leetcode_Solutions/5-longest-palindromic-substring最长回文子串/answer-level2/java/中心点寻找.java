### 解题思路
寻找回文中心点，向两端遍历，记录回文子串，通过比较最长的回文子串得到最终的结果。对于这个中心点他可能存在两种情况：1：虚拟中心点;2:真实中心点

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
        String resultString = "";
        if (s == null || "".equals(s)) {
            return resultString;
        }
        return getLongestPalindrome(s);
    }

    public String getLongestPalindrome(String s) {
        //中心拓展法  中心点
        int length = s.length();
        //最大的回文数
        String longestPalindrome="";
        for (int x = 0; x < s.length(); x++) {
            //是否继续寻找回文数据的标记
            boolean nextAccess = true;
            //当前节点的存在的最大回文字符串
            String longestPalindromeTemp = "";
            //中心元素centerIndex
            int centerIndex = x;
            //中心节点的前一个索引位置
            int preCenterIndex = centerIndex - 1;
            //中心节点的后一个索引位置
            int nextCenterIndex = centerIndex + 1;
            //1:虚拟中心点
            while ( nextAccess) {
                //aab
                if(preCenterIndex==-1) {
                    //断了记录开始头索引和尾巴索引的位置  cbbd   substring 包左不包右
                    longestPalindromeTemp = s.substring(preCenterIndex + 1, nextCenterIndex - 1);
                    if (longestPalindromeTemp.length() > longestPalindrome.length() ) {
                        longestPalindrome = longestPalindromeTemp;
                    }
                    break;
                }
                if(nextCenterIndex==length+1){
                    longestPalindromeTemp = s.substring(preCenterIndex + 1, nextCenterIndex-1);
                    if (longestPalindromeTemp.length() > longestPalindrome.length() ) {
                        longestPalindrome = longestPalindromeTemp;
                    }
                    break;
                }
                //中心的前一个元素
                char pre = s.charAt(preCenterIndex);
                //虚拟中心后一个元素
                char preNext = s.charAt(nextCenterIndex - 1);  //cbbm
                //找到回文数据了,继续寻找
                if (pre == preNext) {
                    //改变位置
                    preCenterIndex--;
                    //cbbcm
                    //abb
                    nextCenterIndex++;
                } else {
                    //回文数据中断了
                    nextAccess = false;
                    //断了记录开始头索引和尾巴索引的位置  cbbd   substring 包左不包右
                    longestPalindromeTemp = s.substring(preCenterIndex + 1, nextCenterIndex-1);
                    if (longestPalindromeTemp.length() > longestPalindrome.length() && !nextAccess) {
                        longestPalindrome = longestPalindromeTemp;
                    }
                }
            }
            //1:虚拟中心点 结束了,从下一个中心点开始寻找

            //重新初始值
            preCenterIndex=centerIndex - 1;
            nextCenterIndex=centerIndex + 1;
            nextAccess=true;
            //2:真实中心点
            while (nextAccess) {
                if(preCenterIndex==-1||nextCenterIndex==length){
                    //断了记录开始头索引和尾巴索引的位置
                    longestPalindromeTemp = s.substring(preCenterIndex + 1, nextCenterIndex);
                    if (longestPalindromeTemp.length() > longestPalindrome.length() ) {
                        longestPalindrome = longestPalindromeTemp;
                    }
                    break;
                }
                //中心的前一个元素
                char pre = s.charAt(preCenterIndex);
                //虚拟中心后一个元素
                char preNext = s.charAt(nextCenterIndex );
                //找到回文数据了,继续寻找
                if (pre == preNext) {
                    //改变位置
                    preCenterIndex--;
                    nextCenterIndex++;
                } else {
                    //回文数据中断了
                    nextAccess = false;
                    //断了记录开始头索引和尾巴索引的位置
                    longestPalindromeTemp = s.substring(preCenterIndex + 1, nextCenterIndex);
                    if (longestPalindromeTemp.length() > longestPalindrome.length() ) {
                        longestPalindrome = longestPalindromeTemp;
                    }
                }
            }
            //2:真实中心点 结束了,从下一个中心点开始寻找
        }
    return longestPalindrome;
    }
}

```