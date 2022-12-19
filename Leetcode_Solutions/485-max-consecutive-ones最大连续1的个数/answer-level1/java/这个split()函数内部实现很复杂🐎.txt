### 解题思路
执行用时 :
908 ms
, 在所有 java 提交中击败了
5.07%
的用户
内存消耗 :
41.1 MB
, 在所有 java 提交中击败了
81.78%
的用户

### 代码

```java
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int res=0;
        String str_nums="";
        for(int n:nums){
            str_nums+=String.valueOf(n);
        }
        String [] str_nums_split=str_nums.split("0");
        for(String s:str_nums_split){
            if(s.length()>res){
                res=s.length();
            }
        }
        return res;
    }
}
```